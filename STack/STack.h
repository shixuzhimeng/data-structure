#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//静态
// #define N 10
// struct Stack
// {
//     int a[N];
//     int top;
// };

typedef int STDataType;

//动态
typedef struct Stack
{
    int* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps);
void STDestory(ST* ps);

void STPush(ST* ps,STDataType x);
void STPop(ST* ps);

int STSize(ST* ps);
bool STEmpty(ST* ps);
STDataType STTop(ST* ps);