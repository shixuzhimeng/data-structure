#include <stdio.h>
#include <stdlib.h>
void Func(int** ptr)
{
    *ptr = (int*)malloc(sizeof(int));
}
int main()
{
    int* px = NULL;
    Func(&px);

    free(px);
    return 0;
}