#include "Heap.h"

void HeapInit(HP* php)
{
    assert(php);

    php->a = (HPDataType*)malloc(sizeof(HPDataType));
    if(php->a == NULL)
    {
        perror("malloc failed");
        return ;
    }
    php->size = 0;
    php->capacity = 4;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType x = *p1;
    *p1 = *p2;
    *p2 = x;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
    int parent = (child - 1)/2;
    //while(parent >= 0)
    while(child > 0)
    {
        if(a[child] > a[parent]) //大根堆
        //if(a[child] < a[parent]) //小根堆
        {
            Swap(&a[child], a[parent]);
            child = parent;
            parent = (child - 1)/2;
        }
        else
        {
            break;
        }
    }
}

void HeapPush(HP* php, HPDataType x)
{
    assert(php);

    if(php->size == php->capacity)
    {
        HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType)*php->capacity*2);
        if(tmp == NULL)
        {
            perror("realloc failed");
            return ;
        }
        php->a = tmp;
        php->capacity *= 2;
    }

    php->a[php->size] = x;
    php->size++;

    AdjustUp(php->a, php->size-1);
}

//左右子树都是大堆/小堆
void HeapDown(HPDataType* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while(child < n)
    {
        //选出左右孩子中最大的一个
        if(child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }

        if(a[child] > a[parent]) //大根堆
        //if(a[child] < a[parent]) //小根堆
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapPop(HP* php)
{
    assert(php);
    assert(HeapEmpty(php));
    
    //数据删除
    Swap(&php->a[0],&php->a[php->size-1]);
    php->size--;

    AdjustDown(php->a, php->size, 0);

}

HPDataType HeapTop(HP* php)
{
    assert(php);
    return php->a[0];
}

bool HeapEmpty(HP* php)
{
    assert(php);
    return php->size == 0;
}

int HeapSize(HP* php)
{
    assert(php);
    return php->size;
}