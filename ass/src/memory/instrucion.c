#include"instruction.h"
#include"dram.h"
#include"cpu/mmu.h"
#include"cpu/register.h"


static uint64_t decode_od(od_t od){
    if(od.type == IMM)
    {
        return od.imm;
    }
    else if(od.type == REG)
    {    
        return *(od.reg1);
    }
    else
    {   
        uint64_t vaddr = 0;
        if(od.type == MM_IMM)
        {
            vaddr = od.imm;
        }
        else if(od.type == MM_REG)
        {   
            vaddr = *(od.reg1);
        }
        else if(od.type == MM_IMM_REG)
        {   
            vaddr = od.imm + *(od.reg1);
        }
        else if(od.type == MM_REG1_REG2)
        {   
            vaddr = *(od.reg1) + *(od.reg2);
        }
        else if(od.type == MM_IMM_REG1_REG2)
        {
            vaddr = od.imm + *(od.reg1) + *(od.reg2);
        }
        else if(od.type == MM_REG2_S)
        {
            vaddr = od.scale * (*(od.reg2));
        }
        else if(od.type == MM_IMM_REG2_S)
        {            
            vaddr = od.imm + od.scale * (*(od.reg2));
        }
        else if(od.type == MM_REG1_REG2_S)
        {    
            vaddr = *(od.reg1) + od.scale * (*(od.reg2));
        }
        else if(od.type == MM_IMM_REG1_REG2_S)
        {
            vaddr = od.imm + *(od.reg1) + od.scale * (*(od.reg2));
        }
        return va2pa(vaddr);
    }
    
}

void instruction_cycle()
{
    inst_t *instr = (inst_t *)reg.rip;//pc 指针 指向下一个需要执行的指令的地址

    // imm: imm
    // reg : value
    // memory: paddr
    uint64_t src = decode_od(instr -> src);
    uint64_t dst = decode_od(instr -> dst);

    handler_t handler = handler_table[instr -> op];
    handler(src,dst);
}

void init_handle_table()
{
    handler_table[add_reg_reg] = &add_reg_reg_handler; 
}

void add_reg_reg_handler(uint64_t src,uint64_t dst)
{
    *(uint64_t *)dst = *(uint64_t *)src + *(uint64_t *)dst;
    reg.rip = reg.rip + sizeof(inst_t);
}