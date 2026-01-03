#include "SeqList.h"

void SeqInit(SL* ps)
{
    //assert(ps);
    ps->a = (SLDataType*)malloc(sizeof(SLDataType)*INIT_CAPACITY);
    if(ps->a == NULL)
    {
        perror("malloc fail");
        return ;
    }
    ps->size = 0;
    ps->capacity = INIT_CAPACITY;
}

void SeqDestory(SL* ps)
{
    assert(ps);
    free(ps->a);
    ps->a == NULL;
    ps->capacity = ps->size = 0;
}

void SeqPrint(SL* ps)
{
    assert(ps);
    for(int i = 0; i < ps->size; i++)
    {
        printf("%d\n",ps->a[i]);
    }
}

void SLCheckCapacity(SL* ps)
{
    assert(ps);
    if(ps->size == ps->capacity)
    {
        SLDataType* tmp =(SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity*2);
        if(tmp == NULL)
        {
            perror("realloc fail");
            return ;
        }
        ps->a = tmp;
        ps->capacity *= 2; 
    }
}

void SeqPushBack(SL* ps, SLDataType x)
{
    assert(ps);
    // SLCheckCapacity(ps);
    // ps->a[ps->size++] = x;
    SLInsert(ps, ps->size, x);
}

void SeqPopBack(SL* ps)
{
    assert(ps);
    //assert(ps->size > 0);
    if(ps->size == 0)
    {
        return ;
    }
    ps->size--;
}

void SeqPushFront(SL* ps, SLDataType x)
{
    // assert(ps);
    // SLCheckCapacity(ps);
    // int end = ps->size - 1;
    // while(end >= 0)
    // {
    //     ps->a[end+1] = ps->a[end];
    //     --end;
    // }
    // ps->a[0] = x;
    // ps->size++;
    SLInsert(ps, 0, x);
}

void SeqPopFront(SL* ps)
{
    assert(ps);
    int begin = 1;
    while(begin < ps->a[begin])
    {
        ps->a[begin - 1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);
    SLCheckCapacity(ps);

    int end = ps->size - 1;
    while(end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        --end;
    }
    ps->a[pos] = x;
    ps->size++;
}

void SLErase(SL* ps,int pos)
{
    assert(ps);
    assert(pos >= 0 && pos < ps->size);

    int begin = pos + 1;
    while(begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}

int SLfind(SL* ps, SLDataType x)
{
	assert(ps);
	for(int i = 0; i < ps->size; i++)
	{
		if(ps->a[i] == x)
		{
		return 1;
		}
	}
}