#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
    LTNode* node = (LTNode*)malloc(sizeof(LTNode));
    if(node == NULL)
    {
        perror("malloc failed");
        return NULL;
        //exit(-1);
    }
    node->next = NULL;
    node->prev = NULL;
    node->data = x;

    return node;
}

LTNode* LTInit()
{
    LTNode* phead = BuyListNode(-1);
    phead->next = phead;
    phead->prev = phead;

    return phead;
}

void LTDestory(LTNode* phead)
{
    assert(phead);
    LTNode* cur = phead->next;
    while(cur != phead)
    {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }

    free(phead);
    phead = NULL;
}

void LTPrint(LTNode* phead)
{
    assert(phead);
    LTNode* cur = phead->next;
    while(cur != phead)
    {
        printf("%d<->",cur->data);
        cur = cur->next;
    }
}

bool LTEmpty(LTNode* phead)
{
    assert(phead);
    
    return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
    assert(phead);

    // LTNode* newNode = BuyListNode(x);
    // LTNode* tail = phead->prev;

    // tail->next = newNode;
    // newNode->prev = tail;
    // newNode->next = phead;
    // phead->prev = newNode;

    LTInsert(phead, x);
}
void LTpopBack(LTNode* phead)
{
    assert(phead);
    assert(LTEmpty(phead));

    LTNode* tail = phead->prev;
    LTNode* tailPrev = tail->prev;

    tailPrev->next = phead;
    phead->prev = tailPrev;
    free(tail);
    tail = NULL;

}

void LTPushFront(LTNode* phead, LTDataType x)
{
    assert(phead);
    LTNode* newNode = BuyListNode(x);
    newNode->next = phead->next;
    phead->next->prev = newNode;
    phead->next = newNode;
    newNode->prev = phead;
}
void LTpopFront(LTNode* phead)
{
    if (!LTEmpty(phead))
    {
        LTErase(phead->next);
    }
}

void LTInsert(LTNode* pos, LTDataType x)
{
    assert(pos);

    LTNode* prev = pos->prev;
    LTNode* newNode = BuyListNode(x);

    prev->next = newNode;
    newNode->prev = prev;

    newNode->next = pos;
    pos->prev = newNode; 
}

void LTErase(LTNode* pos)
{
    assert(pos);
    LTNode* p = pos->prev;
    LTNode* n = pos->next;
    
    p->next = n;
    n->prev = p;
    free(pos);
}

LTNode* LTFind(LTNode* phead,LTDataType x)
{
    LTNode* cur = phead->next;
    while(cur != phead)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
