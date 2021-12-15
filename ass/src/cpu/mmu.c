#include"mmu.h"
#include"memory/dram.h"

// 虚拟内存地址转物理内存地址
uint64_t va2pa(uint64_t vaddr)
{   
    return vaddr % MM_LEN;
}