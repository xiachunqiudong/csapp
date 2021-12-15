#include<stdio.h>
#include"elf.h"
#include"memory/instruction.h"
#include"cpu/register.h"

inst_t program[INST_LEN] = 
{   
    {   
        // mov rax rbx
        MOV,
        { REG, 0, 0,(uint64_t *)&reg.rax, NULL},
        { REG, 0, 0,(uint64_t *)&reg.rbx, NULL}
    }
    
};


