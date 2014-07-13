#include "vm.h"
#include "opcodes.h"

#define lenof(x) sizeof(x)/sizeof(x[0])

int main(int argc, char **argv) 
{
    int code[] = 
    {  
       ICONST, 9,
       ICONST, 1,
       IADD,
       PRINT,
       HALT
    };
    
    VM vm(code, lenof(code), 0, 0); 
	vm.execute();

}
