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

bool VM::execute()
{
	std::cout << "Executing" <<"\n";
	while(m_ip < m_codeSize)
	{
		int opcode = m_code[m_ip++];
		switch(opcode)
		{
			case HALT:
				break;
            case ICONST:
            {
                int operand = m_code[m_ip++]; 
                m_stack[m_sp++] = operand;
                break;
            }
            case PRINT:
            {
                int val = m_stack[--m_sp];
                std::cout << val <<"\n";
                break;
            }
            case IADD:
            {
                int val1 = m_stack[--m_sp];
                int val2 = m_stack[--m_sp];
                int res = val1 + val2;
                m_stack[m_sp++] = res;
                break;
            }
		}
	}
	return true;
}



