#include "vm.h"
#include "opcodes.h"

#include <iostream>

#define DECODE 
#define lenof(x) sizeof(x)/sizeof(x[0])

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

using std::cout;
bool VM::execute()
{
	cout << "Executing" <<"\n";
	while(m_ip < m_codeSize)
	{
		int opcode = m_code[m_ip++];
		switch(opcode)
		{
			case OPC_HALT:
				break;
            case OPC_ICONST:
            {
                int operand = m_code[m_ip++]; 
                cout << OPCODE_toString(OPC_ICONST) << " " << operand << "\n";
                m_stack[m_sp++] = operand;
                break;
            }
            case OPC_PRINT:
            {
                int val = m_stack[--m_sp];
                cout << val <<"\n";
                break;
            }
            case OPC_IADD:
            {
                int val1 = m_stack[--m_sp];
                int val2 = m_stack[--m_sp];
                int res = val1 + val2;
                m_stack[m_sp++] = res;
                break;
            }
            case OPC_ISUB:
            {
                int val1 = m_stack[--m_sp];
                int val2 = m_stack[--m_sp];
                int res = val1 - val2;
                m_stack[m_sp++] = res;
                break;
                
            }
            case OPC_JNZ:
            {
                int val = m_stack[--m_sp];
                if(val != 0)
                    m_ip = m_code[m_ip];
                break;
            }
            case OPC_JZ:
            {
                int val = m_stack[--m_sp];
                if(val == 0)
                    m_ip = m_code[m_ip];
                break;
            }
            case OPC_ISTORE:
            {
                int addr = m_code[m_ip++]; 
                int val = m_stack[--m_sp];
                m_data[addr] = val;
                break;
            }
            case OPC_ILOAD:
            {
                int addr = m_code[m_ip++]; 
                m_stack[m_sp++] = m_data[addr];
                break;
            }
		}
	}
	return true;
}



