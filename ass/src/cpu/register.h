#include<stdint.h>
#include<stdlib.h>

// REG
typedef struct REG_STRUCT 
{   
    //x86 共16个寄存器
    // 寄存器文件
    union // union是共享内存的
    {   
        struct // 内存是连续分布的
        {   
            uint8_t al;
            uint8_t ah;//内存对齐
        };
        uint16_t ax;
        uint32_t eax;
        uint64_t rax;
    };
    
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rbp;
    uint64_t rsp;
    // program counter >> pc
    uint64_t rip;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;


} reg_t;

//寄存器文件
reg_t reg;


