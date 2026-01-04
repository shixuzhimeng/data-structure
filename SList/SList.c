#include "SList.h"

void SLTPrintf(SLTNode* phead)
{
    SLTNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d->", cur->data);
    }
}

SLTNode* BuySLTNode(SListDataType x)
{
    SLTNode* newnode = (SLTNode *)malloc(sizeof(SLTNode));
    if(newnode == NULL)
    {
        perror("malloc fail");
        return ;
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void SLTPushBack(SLTNode** phead, SListDataType x)
{
    SLTNode* newnode = BuySLTNode(x);
    if(*phead == NULL)
    {
        *phead == newnode;
    }
    else
    {
        SLTNode * tail = *phead;
        while(tail != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void SLTPushFront(SLTNode** phead, SListDataType x)
{
    SLTNode* newnode = BuySLTNode(x);
    newnode->next = *phead;
    *phead = newnode;
}

void SLTPopBack(SLTNode** phead)
{
    if(*phead == NULL)
    {
        return ;
    }
    if((*phead)->next == NULL)
    {
        free(*phead);
        *phead = NULL;
    }
    else
    {
        SLTNode* tail =*phead;
        while(tail->next->next != NULL)
        {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

void SLTPopFront(SLTNode** phead)
{
    SLTNode* first = *phead;
    *phead = first->next;
    free(first);
    first = NULL;
}

SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
    SLTNode* cur = phead;
    while(cur)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;

    }
    return NULL;
}

void SListInsert(SLTNode** phead, SLTNode* pos, SListDataType x)
{
    assert(pos);
    assert(phead);
    if(pos == *phead)
    {
        SLTPushFront(phead, x);
    }
    else
    {
        SLTNode* prev = (SLTNode*)malloc(sizeof(SLTNode));
        while(prev != pos)
        {
            prev = prev->next;
        }
        SLTNode* newnode = BuySLTNode(x);
        prev->next = newnode;
        newnode->next = pos;
    }
}

void SListErase(SLTNode** phead, SLTNode* pos)
{
    assert(pos);
    assert(phead);
    if(*phead == pos)
    {
        SLTPopBack(phead);
    }
    else
    {
        SLTNode* prev = *phead;
        while(prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
    }
}


void SListInsertAfter(SLTNode* pos, SListDataType x)
{
    assert(pos);
    SLTNode* newnode = BuySLTNode(x);
    pos->next = newnode;
    newnode->next = pos->next;
}

void SListEraseAfter(SLTNode* pos)
{
    assert(pos);
    assert(pos->next);

    SLTNode* del = pos->next;
    pos->next = del->next;
    free(del);
    del = NULL;
}