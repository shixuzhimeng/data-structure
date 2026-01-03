typedef int SLDataType;
#define N 1000
//静态顺序表（开多了浪费，开少了不够用）
struct SeqList
{
    SLDataType a[N];
    int size;
};

typedef int SLDataType;
//动态顺序表
struct SeqList
{
    SLDataType* a;
    int size;         //有效数据个数
    int capacity;     //空间容量
};