#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap {
    HPDataType* x;
    int size;
    int capacity;
}HP;

void HeapInit(HP* php) {
    assert(php);
    php->x = (HPDataType*)malloc(sizeof(HPDataType));
    if(php->x == NULL) {
        perror("malloc failed");
        return ;
    }
    php->size = 0;
    php->capacity = 4;
}

void HeapInitArray(HP* php, int*x, int n) {
    assert(php);
    php->x = (HPDataType*)malloc(sizeof(HPDataType));
    if(php->x == NULL)
    {
        perror("malloc failed");
        return ;
    }

    php->size = n;
    php->capacity = n;

    //建堆
    for(int i = (n-2)/2; i >= 0; --i)
    {
        AdjustDown(php->x, php->size, i);
    }
}

void HeapDestory(HP* php) {
    assert(php);
    free(php->x);
    php->x = NULL;;
    php->size = 0;
    php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2) {
    HPDataType z = *p1;
    *p1 = *p2;
    *p2 = z;
}

void AdjustUp(HPDataType* x, int child) {
    //找到其父结点的索引值
    int parent = (child - 1) / 2;
    while (child > 0) {
        if(x[child] > x[parent]) {
            //交换
            Swap(&x[child], &x[parent]);
            //更新
            child = parent;
            parent = (child - 1) / 2;
        } else {
            break;
        }
    }
}

void HeapPush(HP *php,HPDataType a) {
    assert(php);
    if(php->size == php->capacity) {
        HPDataType* tmp = (HPDataType*)realloc(php->x, sizeof(HPDataType)*php->capacity*2);
        if(tmp == NULL) {
            perror("realloc failed");
            return ;
        }
        php->x = tmp;
        php->capacity *= 2;
    }

    php->x[php->size] = a;
    php->size++;

    AdjustUp(php->x, php->size-1);

}

void AdjustDown(HPDataType* x, int n, int parent) {
    //左子结点的索引值
    int child = parent * 2 + 1;
    while (child < n) {
        if(child + 1 < n && x[child + 1] < x[child])
        {
            ++child;  // 指向右子结点
        }

        //交换元素
        //if(x[child] > x[parent]) //大根堆
        if(x[child] < x[parent]) //小根堆
        {
            Swap(&x[child], &x[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
bool HeapEmpty(HP* php)
{
    assert(php);
    return php->size == 0;
}
void HeapPop(HP* php)
{
    assert(php);
    assert(HeapEmpty(php));
    
    //数据删除
    Swap(&php->x[0],&php->x[php->size-1]);
    php->size--;

    AdjustDown(php->x, php->size, 0);

}

HPDataType HeapTop(HP* php)
{
    assert(php);
    return php->x[0];
}

int HeapSize(HP* php)
{
    assert(php);
    return php->size;
}

int main() {

}