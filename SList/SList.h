#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int SListDataType;

//节点
typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SLTNode;

//打印
void SLTPrintf(SLTNode* head);

//头插尾插
void SLTPushBack(SLTNode** phead, SListDataType x);
void SLTPushFront(SLTNode** phead, SListDataType x);
//头删尾删
void SLTPopBack(SLTNode** phead);
void SLTPopFront(SLTNode** phead);

//查找
SLTNode* SListFind(SLTNode* phead, SListDataType x);

//某位置前插入删除
void SListInsert(SLTNode** phead, SLTNode* pos, SListDataType x);
void SListErase(SLTNode** phead, SLTNode* pos);


//某位置后插入删除
void SListInsertAfter(SLTNode* pos, SListDataType x);
void SListEraseAfter(SLTNode* pos);