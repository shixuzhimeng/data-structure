#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int SListDataType;

typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SLTNode;

void SLTPrintf(SLTNode* head);