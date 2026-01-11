#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);

    pq->head = pq->tail = NULL;
    pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);

    QNode* cur = pq->head;
    while(cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    pq->head = pq->tail = NULL;
    pq->tail = 0;
}

void QueuePush(Queue* pq,QDataType x)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if(newNode)
    {
        perror("malloc failed");
        return ;
    }

    newNode->data = x;
    newNode->next = NULL;

    if(pq->head == NULL)
    {
        assert(pq->tail == NULL);
        pq->head = pq->tail = newNode;
    }
    else
    {
        pq->tail->next = newNode;
        pq->tail = newNode;
    }

    pq->size++;
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head != NULL);
    // QNode* next = pq->head->next;
    // free(pq->head);
    // pq->head = next;
    // if(pq->head == NULL)
    //     pq->tail = NULL;

    if(pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }

    pq->size--;
}

void QueueSize(Queue* pq)
{
    assert(pq);

    return pq->size;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);

    return pq->size == 0;
}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->tail->data;
}