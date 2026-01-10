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
}

void QueuePop(Queue* pq);

void QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
