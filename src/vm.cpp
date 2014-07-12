#include "vm.h"
#include "opcodes.h"

#include <iostream>

#define DECODE 
#define lenof(x) sizeof(x)/sizeof(x[0])

VM::VM(int code[], int stackSize, int dataSize)
: m_stackSize(stackSize),
  m_dataSize(dataSize),
  m_fp(0),
  m_sp(0),
  m_ip(0)
{
	m_stack = new int[m_stackSize];
	m_data = new int[m_dataSize];
    m_codeSize = lenof(code);
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
	while(m_ip < lenof(m_code))
	{
		int opcode = m_code[m_ip++];
		switch(opcode)
		{
			case HALT:
				std::cout<< "Bye";
				break;
		}
	}
	return true;
}



