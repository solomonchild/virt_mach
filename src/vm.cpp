#include "vm.h"

#include <iostream>

#include "opcodes.h"


#define lenof(x) sizeof(x)/sizeof(x[0])

using std::cout;

VM::VM(int *code, int codeSize, int stackSize, int dataSize)
: m_stackSize(stackSize),
  m_dataSize(dataSize),
  m_codeSize(codeSize),
  m_fp(0),
  m_sp(0),
  m_ip(0)
{
	m_stack = new int[m_stackSize];
	m_data = new int[m_dataSize];
    m_code = code;
}

VM::~VM()
{
	delete(m_stack);
	delete(m_data);
}


void VM::trace(int opcode, int params = 0)
{
    cout << "[" << m_ip - 1 << "]: " << OPCODE_toString(opcode);
    for(int i = 0; i < params; i++)
        cout << " " << m_code[m_ip + i] << " ";
    cout << "\n";
}

bool VM::execute()
{
	cout << "VM started" <<"\n";
	while(m_ip < m_codeSize)
	{
		int opcode = m_code[m_ip++];
		switch(opcode)
		{
			case OPC_HALT:
                trace(OPC_HALT);
				break;
            case OPC_ICONST:
            {
                trace(OPC_ICONST, 1);
                int operand = m_code[m_ip++]; 
                m_stack[m_sp++] = operand;
                break;
            }
            case OPC_PRINT:
            {
                trace(OPC_PRINT);
                int val = m_stack[--m_sp];
                cout << val <<"\n";
                break;
            }
            case OPC_IADD:
            {
                trace(OPC_IADD);
                int val1 = m_stack[--m_sp];
                int val2 = m_stack[--m_sp];
                int res = val1 + val2;
                m_stack[m_sp++] = res;
                break;
            }
            case OPC_ISUB:
            {
                trace(OPC_ISUB);
                int val1 = m_stack[--m_sp];
                int val2 = m_stack[--m_sp];
                int res = val1 - val2;
                m_stack[m_sp++] = res;
                break;
                
            }
            case OPC_JNZ:
            {
                trace(OPC_JNZ);
                int val = m_stack[--m_sp];
                if(val != 0)
                    m_ip = m_code[m_ip];
                break;
            }
            case OPC_JZ:
            {
                trace(OPC_JZ);
                int val = m_stack[--m_sp];
                if(val == 0)
                    m_ip = m_code[m_ip];
                break;
            }
            case OPC_ISTORE:
            {
                trace(OPC_ISTORE, 1);
                int addr = m_code[m_ip++]; 
                int val = m_stack[--m_sp];
                m_data[addr] = val;
                break;
            }
            case OPC_ILOAD:
            {
                trace(OPC_ILOAD, 1);
                int addr = m_code[m_ip++]; 
                m_stack[m_sp++] = m_data[addr];
                break;
            }
		}
	}
	return true;
}



