#include <stdio.h>
#include <stdlib.h>
// void func(int y)
// {
//     y = 1;
// }


// int main()
// {
//     int x = 0;
//     func(x);
//     printf("%d",x);
//     return 0;

// }

// void func(int* p)
// {
//     *p = 1;
// }
// int main()
// {
//     int x = 0;
//     func(&x);
//     printf("%d",x);
//     return 0;
// }


//ptr的改变不会影响到px的改变
// void Func(int* ptr)
// {
//     ptr = (int*)malloc(sizeof(int));
// }
// int main()
// {
//     int* px = NULL;
//     Func(px);
//     return 0;
// }


//理解二级指针
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