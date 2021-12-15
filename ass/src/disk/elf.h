#include<stdint.h>
#include<stdlib.h>
#include"memory/instruction.h"

// 指令个数 宏定义 
// 普通 int len = 100 会把这个变量分配到stack
// #define 宏定义 会在预处理阶段的时候直接换成100 c不能用一个不确定的数对数组进行初始化
#define INST_LEN 100

inst_t program[INST_LEN];