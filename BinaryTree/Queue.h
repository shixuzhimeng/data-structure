#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
    int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq,QDataType);
void QueuePop(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);