#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* a;
    int size;         //有效数据个数
    int capacity;     //空间容量
}SL;

void SeqInit(SL* ps)
{
    assert(ps);
    ps->a = (SLDataType*)malloc(sizeof(SLDataType));
    ps->size = 0;
    ps->capacity = 4;
}

void SeqDestory(SL* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void SeqPrint(SL* ps)
{
    assert(ps);
    for(int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
}

void SLCheckCapacity(SL* ps)
{
    if(ps->capacity == ps->size)
    {
        SLDataType* tmp = (SLDataType*)realloc(ps->a,sizeof(SLDataType)*ps->capacity);
        if(tmp == NULL)
        {
            perror("realloc failed");
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    
}


void SeqPushBack(SL* ps, SLDataType x)
{
    assert(ps);
    SLCheckCapacity(ps);
    ps->a[ps->size++] = x;
}

void SeqPopBack(SL* ps)
{
    assert(ps);
    if(ps->size == 0)
    {
        return ;
    }
    ps->size--;
}

void SeqPushFront(SL* ps, SLDataType x)
{
    assert(ps);
    SLCheckCapacity(ps);

    int end = ps->size-1;
    while(end >= 0)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqPopFront(SL* ps)
{
    assert(ps);
    int begin = 1;
    while(begin < ps->size)
    {
        ps->a[begin-1] = ps->a[begin];
        begin++;
    }
    ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    int end = ps->size - 1;
    while(end > pos)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}

void SLErase(SL* ps,int pos)
{
    assert(ps);
    int begin = pos + 1;
    while(begin < ps->size)
    {
        ps->a[begin-1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}

int SLfind(SL* ps, SLDataType x)
{
    assert(ps);
    for(int i = 0; i < ps->size; i++)
    {
        if(ps->a[i] = x)
        {
            return i;
        }
    }
}


int main()
{
    SL ps;
    SeqInit(&ps);



    SeqDestory(&ps);
}