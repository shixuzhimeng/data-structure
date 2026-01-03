#include "SList.h"

void SLTPrintf(SLTNode* phead)
{
    SLTNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d->", cur->data);
    }
}