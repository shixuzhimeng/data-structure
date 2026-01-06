#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int LTDataType;

typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;

    LTDataType data;
}LTNode;

LTNode* LTInit();
void LTDestory(LTNode* phead);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTpopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTpopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead,LTDataType x);
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

