#include "vm.h"
#include "opcodes.h"

#define lenof(x) sizeof(x)/sizeof(x[0])

int main(int argc, char **argv) 
{
    int code[] = 
    {  
       ICONST, 0, //00
       ISTORE, 0, //02
       ILOAD, 0,  //04
       ICONST, 1,//06
       IADD,    //08
       ISTORE, 0, //09
       ILOAD, 0,
       ICONST, 10, //11
       ISUB,      //13
       JNZ, 04,        //14
       ILOAD,0,
       PRINT,     //15
       HALT       //16
    };
    
    VM vm(code, lenof(code), 1, 0); 
	vm.execute();

}
