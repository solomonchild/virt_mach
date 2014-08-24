#include "opcodes.h" 

void trim(std::string &toTrim)
{
    auto it = toTrim.begin();
    auto end = toTrim.end();
    while((*it) == ' ' && it != end)
        ++it;
    toTrim.erase(toTrim.begin(), it); 

    while((*end) == ' ' && it != end)
        --end;
    toTrim.erase(end, toTrim.end()); 
}

std::vector<std::string> split(std::string str, char delim)
{

    std::vector<std::string> to_ret;
    auto it = str.begin();
    auto prev_it = it;
    for(; it < str.end(); it++)
    {
        if(*it == delim)
        {
            std::string str(prev_it, it);
            trim(str);
            to_ret.push_back(str);
            prev_it = it + 1;
        }
    }
    return to_ret;
}
std::vector<std::string> OPCODE_Map = split(OPCODE_STRING, ',');
const char* OPCODE_toString(unsigned val) 
{
    if(val >= 0 && val < (int) OPCODE_Map.size())
        return OPCODE_Map[val].c_str();
    else return NULL;
}

