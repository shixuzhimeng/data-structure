#include <stdio.h>
#include "test3.c"
void HeapSort(int* x, int n) {
    // for(int i = 0; i < n; i++) {
    //     AdjustUp(x, i);
    // }

    for(int i = (n - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(x, n, i);
    }

    int end = n - 1;
    while(end > 0)
    {
        Swap(&x[end], &x[0]);
        AdjustDown(x, end, 0);
        --end;
    }
    return 0;
}