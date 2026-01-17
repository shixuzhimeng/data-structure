#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

typedef struct DequeNode
{
    QDataType data;
    struct DequeNode* prev;
    struct DequeNode* next;
} DequeNode;

typedef struct Deque
{
    DequeNode* head;
    DequeNode* tail;
    int size;
} Deque;

void DequeInit(Deque* pdq)
{
    assert(pdq);
    pdq->head = pdq->tail = NULL;
    pdq->size = 0;
}

void DequeDestroy(Deque* pdq)
{
    assert(pdq);
    DequeNode* cur = pdq->head;
    while(cur)
    {
        DequeNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pdq->head = pdq->tail = NULL;
    pdq->size = 0;
}

//从队头进
void DequePushFront(Deque* pdq, QDataType x)
{
    assert(pdq);
    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if (newNode == NULL)
    {
        perror("malloc failed");
        return;
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = pdq->head;

    if(pdq->head)
    {
        pdq->head->prev = newNode;
    }
    pdq->head = newNode;
    if(pdq->tail == NULL)
    {
        pdq->tail = newNode;
    }
    pdq->size++;
}

//从队头出
void DequePopFront(Deque* pdq)
{
    assert(pdq);
    if(pdq->head == NULL)
    {
        printf("Deque is empty!\n");
        return;
    }
    DequeNode* toDelete = pdq->head;
    pdq->head = pdq->head->next;
    if(pdq->head)
    {
        pdq->head->prev = NULL;
    }
    else
    {
        pdq->tail = NULL;
    }
    free(toDelete);
    pdq->size--;
}

//从队尾进
void DequePushBack(Deque* pdq, QDataType x)
{
    assert(pdq);
    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    if(newNode == NULL)
    {
        perror("malloc failed");
        return;
    }
    newNode->data = x;
    newNode->prev = pdq->tail;
    newNode->next = NULL;

    if(pdq->tail)
    {
        pdq->tail->next = newNode;
    }
    pdq->tail = newNode;
    if(pdq->head == NULL)
    {
        pdq->head = newNode;
    }
    pdq->size++;
}

//从队尾出
void DequePopBack(Deque* pdq)
{
    assert(pdq);
    if(pdq->tail == NULL)
    {
        printf("Deque is empty!\n");
        return;
    }
    DequeNode* toDelete = pdq->tail;
    pdq->tail = pdq->tail->prev;
    if(pdq->tail)
    {
        pdq->tail->next = NULL;
    }
    else
    {
        pdq->head = NULL;
    }
    free(toDelete);
    pdq->size--;
}

int DequeSize(Deque* pdq)
{
    assert(pdq);
    return pdq->size;
}

QDataType DequeFront(Deque* pdq)
{
    assert(pdq);
    assert(pdq->head != NULL);
    return pdq->head->data;
}

QDataType DequeBack(Deque* pdq)
{
    assert(pdq);
    assert(pdq->tail != NULL);
    return pdq->tail->data;
}