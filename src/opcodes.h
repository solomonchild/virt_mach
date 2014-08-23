#ifndef _OPCODES_H_
#define _OPCODES_H_

#include <string>
#include <utility>
#include <vector>
#include <iostream>
using std::cout;

inline std::vector<std::string> split(std::string str, char delim)
{

    std::vector<std::string> to_ret;
    auto it = str.begin();
    auto prev_it = it;
    for(; it < str.end(); it++)
    {
        if(*it == delim)
        {
            to_ret.push_back(std::string(prev_it, it));
            prev_it = it;
        }
    }
    return to_ret;
}

#define MAKE_STR_ENUM(name, ...) \
enum name {\
__VA_ARGS__\
};\
static std::vector<std::string> name##Map = split(#__VA_ARGS__, ',');\
inline const char* name##_toString(unsigned val) {\
    if(val >= 0 && val < (int) name##Map.size())\
        return name##Map[val].c_str();\
    else return NULL;\
}\

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
