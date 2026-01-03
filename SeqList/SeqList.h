#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// typedef int SLDataType;
// #define N 1000
// //静态顺序表（开多了浪费，开少了不够用）
// struct SeqList
// {
//     SLDataType a[N];
//     int size;
// };


typedef int SLDataType;
#define INIT_CAPACITY 4


//动态顺序表 -- 按需申请
typedef struct SeqList
{
    SLDataType* a;
    int size;         //有效数据个数
    int capacity;     //空间容量
}SL;

//增删查改
void SeqInit(SL* ps);

void SeqDestory(SL* ps);

void SeqPrint(SL* ps);

void SLCheckCapacity(SL* ps);


void SeqPushBack(SL* ps, SLDataType x);
void SeqPopBack(SL* ps);
void SeqPushFront(SL* ps, SLDataType x);
void SeqPopFront(SL* ps);

void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps,int pos);

int SLfind(SL* ps, SLDataType x);