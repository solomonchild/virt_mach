#ifndef _VM_H_
#define _VM_H_

class VM
{
public:
    VM(int *code, int codeSize, int stackSize, int dataSize);
    bool execute();
    ~VM();
protected:
    int m_stackSize;
    int m_dataSize;
    int m_codeSize;
    int *m_code;
    int m_fp, m_sp, m_ip;
    int *m_stack;
    int *m_data;

};


#endif //_VM_H_
