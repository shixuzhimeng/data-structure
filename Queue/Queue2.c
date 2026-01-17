#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_SIZE 5 

typedef int QDataType;

typedef struct Queue 
{
    QDataType data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->front = pq->rear = 0;
}

// 销毁队列
void QueueDestroy(Queue* pq)
{
    assert(pq);
}

// 判断队列是否为空
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->front == pq->rear;
}

// 判断队列是否满
bool QueueFull(Queue* pq)
{
    assert(pq);
    return (pq->rear + 1) % MAX_SIZE == pq->front;
}

// 入队操作
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);

    if(QueueFull(pq))
    {
        printf("Queue is full!\n");
        return;
    }

    pq->data[pq->rear] = x;
    pq->rear = (pq->rear + 1) % MAX_SIZE;
}

// 出队操作
void QueuePop(Queue* pq)
{
    assert(pq);
    if(QueueEmpty(pq))
    {
        printf("Queue is empty!\n");
        return;
    }

    pq->front = (pq->front + 1) % MAX_SIZE;
}

// 获取队列大小
int QueueSize(Queue* pq)
{
    assert(pq);
    return (pq->rear - pq->front + MAX_SIZE) % MAX_SIZE;
}

// 查看队列头部元素
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    if(QueueEmpty(pq))
    {
        printf("Queue is empty!\n");
        return -1;
    }

    return pq->data[pq->front];
}

// 查看队列尾部元素
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    if(QueueEmpty(pq))
    {
        printf("Queue is empty!\n");
        return -1;
    }

    return pq->data[(pq->rear - 1 + MAX_SIZE) % MAX_SIZE];
}