#include "vm.h"
#include "opcodes.h"

int main(int argc, char **argv) 
{
    int code[] = { HALT };
    VM vm(code, 0, 0); 
	vm.execute();

}
