#include<stdint.h>
#include<stdlib.h>

#define NUM_INSTRUCTION 30


// 操作码
typedef enum OP
{
    MOV,
    PUSH, 
    CALL,
    add_reg_reg
} op_t;

// 操作数类型
typedef enum OD_TYPE
{
    IMM,
    REG,
    MM_IMM,
    MM_REG,
    MM_IMM_REG,
    MM_REG1_REG2,
    MM_IMM_REG1_REG2,
    MM_REG2_S,
    MM_IMM_REG2_S,
    MM_REG1_REG2_S,
    MM_IMM_REG1_REG2_S
} od_tpye_t;

// 操作数
typedef struct OD
{   
    od_tpye_t type;
    
    int64_t imm;// 立即数是有符号数
    uint64_t scale;// 比例因子
    uint64_t *reg1;// 基址寄存器
    uint64_t *reg2;// 变址寄存器

    char code[100];
} od_t;

// 指令结构
typedef struct INSTRUCT_STRUCT
{
    op_t op;//操作码
    od_t src;//源操作数
    od_t dst;//目的操作数
} inst_t;

// 定义了个函数 返回值 void 参数是 uint64_t uint64_t
typedef void(*handler_t)(uint64_t,uint64_t);

handler_t handler_table[NUM_INSTRUCTION];

// 解析操作数
uint64_t decode_od(od_t od);

// 指令周期
void instruction_cycle();

void add_reg_reg_handler(uint64_t src,uint64_t dst);

