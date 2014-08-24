#ifndef _OPCODES_H_
#define _OPCODES_H_

#include <string>
#include <utility>
#include <vector>
#include <iostream>
using std::cout;

std::vector<std::string> split(std::string str, char delim);

#define MAKE_STR_ENUM(name, ...) \
enum name {\
__VA_ARGS__\
,name##_END,\
};\
static const char *name##_STRING = #__VA_ARGS__; \
extern const char* name##_toString(unsigned val);

MAKE_STR_ENUM(OPCODE,
    OPC_ICONST,
    OPC_IADD,
    OPC_ISUB,
    OPC_PRINT,
    OPC_HALT,
    OPC_JZ,
    OPC_JNZ,
    OPC_ISTORE,
    OPC_ILOAD,
    OPC_ENUM_END
);


#endif //_OPCODES_H_
