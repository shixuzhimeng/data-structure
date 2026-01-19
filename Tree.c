#include <stdio.h>

// //树的度为n
// #define N 5
// struct TreeNode
// {
//     struct TreeNode* children[N];//指针数组
//     int data;
// };

// //不知道度为多少
// struct TreeNode
// {
//     SeqList s1;   //存的数据类型struct TreeNode*
//     int data;
// };

typedef struct TreeNode
{
    int data;               // 存储节点数据
    struct TreeNode* firstChild;  // 指向第一个子节点的指针
    struct TreeNode* nextSibling; // 指向下一个兄弟节点的指针
} TreeNode;

int main()
{
    return 0;
}