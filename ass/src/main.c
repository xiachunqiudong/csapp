#include<stdio.h>
#include<stdint.h>


int main(){
    uint64_t a = 100;
    uint64_t *b = a;
    printf("a = %d \n",a);
    printf("b = %x \n",b);
    printf("*b = %d \n",*b);
    return 0;
}
