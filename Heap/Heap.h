#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int HPDataType;

typedef struct Heap
{
    HPDataType* a;
    int size;
    int capacity;
}HP;

void HeapInit(HP* php);
void HeapInitArray(HP* php, int *a, int n);
void HeapDestory(HP* php);

void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);

void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);

HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);