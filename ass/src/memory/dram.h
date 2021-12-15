#include<stdint.h>

// 内存 >> 很大的字节数组 字节是内存中最小的存储单元 每一个byte都对应一个64位的地址
#define MM_LEN 1000 //1000byte 大小的内存

uint8_t mm[MM_LEN]; //pyhsical memory 不可以直接读取物理内存

// virtual memory 0 -> 0xffffffffffffffff 64位地址
// physical memory 000 -> 999
// 建立一个 va -> pa 的映射