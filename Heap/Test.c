#include "Heap.h"

// int main()
// {
//     HP hp;
//     HeapInit(&hp);
//     HeapPush(&hp,4);
//     return 0;
// }

//堆排序
//排升序建大堆
//排降序建小堆
//时间复杂度：O(N*logN)
void HeapSort(int* a, int n)
{
    //建堆 -- 向上调整建堆
    //时间复杂度O(N*logN)
    // for(int i = 1; i < n; i++)
    // {
    //     AdjustUp(a, i);
    // }

    //建堆 -- 向下调整建堆
    //时间复杂度O(N)
    for(int i = (n -1 - 1)/2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }
    
    //向下调整完成堆排序
    //时间复杂度O(N*logN)
    int end = n - 1;
    while(end > 0)
    {
        Swap(&a[end], &a[0]);
        AdjustDown(a, end, 0);
        --end;
    }
}

int main()
{
    int a[10] = {2,1,5,7,6,8,0,9,4,3};
    HeapSort(a,10);

    return 0;
}