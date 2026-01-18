#include "Heap.h"
#include <time.h>

void PrintTopK(const char* file, int k)
{
    //建堆--用a中的前K个元素建堆
    int* topK = (int*)malloc(sizeof(int)*k);
    assetr(topK);

    const char* file = "data.txt";
    FILE* fout = fopen(file, "w");
    if(fout == NULL)
    {
        perror("fopen failed");
        return ;
    }

    //读出前K个数建堆
    for(int i = 0; i < k; ++i)
    {
        fscanf(fout, "%d", &topK[i]);
    }

    for(int i = (k-2)/2; i >= 0; --i)
    {
        AdjustDown(topK,k,i);
    }

    //将剩余的N-K个数据依次与堆顶元素交换
    int val = 0;
    int ret = fscanf(fout, "%d", &val);
    while(ret != EOF)
    {
        if(val > topK[0])
        {
            topK[0] = val;
            AdjustDown(topK, k, 0);
        }
        ret = fscanf(fout, "%d", &val);
    }
    for(int i = 0; i < k; i++)
    {
        printf("%d ",topK[i]);
    }
    printf("\n");

    free(fout);
    fclose(fout);
}

void CreatNData()
{
    int n = 10000;
    srand(time(0));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if(fin == NULL)
    {
        perror("fopen failed");
        return ;
    }
    for(size_t i = 0; i < n; i++)
    {
        int x = rand()%10000;
        fprintf(fin, "%d\n", x);
    }

    fclose(fin);
}

int main()
{
    CreatNData();
    PrintfTopK("data.txt", 10);

    return 0;
}