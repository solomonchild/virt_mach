#include "vm.h"
#include "opcodes.h"

#define lenof(x) sizeof(x)/sizeof(x[0])

int main(int argc, char **argv) 
{
    int code[] = 
    {  
       OPC_ICONST, 0, //00
       OPC_ISTORE, 0, //02
       OPC_ILOAD, 0,  //04
       OPC_ICONST, 1,//06
       OPC_IADD,    //08
       OPC_ISTORE, 0, //09
       OPC_ILOAD, 0,
       OPC_ICONST, 10, //11
       OPC_ISUB,      //13
       OPC_JNZ, 04,        //14
       OPC_ILOAD,0,
       OPC_PRINT,     //15
       OPC_HALT       //16
    };
    
    VM vm(code, lenof(code), 1, 0); 
	vm.execute();

}
