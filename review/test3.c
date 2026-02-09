#include <stdio.h>

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

void HeapPush(HP *php) {

}

int main() {

}