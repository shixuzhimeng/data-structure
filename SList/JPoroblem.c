#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体，代表环中的一个人
typedef struct Node {
    int value;          // 人的编号
    struct Node *next;  // 指向下一个节点的指针
} Node;

/**
 * 约瑟夫环问题链表实现
 * @param n 总人数
 * @param k 起始报数的位置（从1开始）
 * @param m 报数到m的人出列
 * @return 最后存活的人的编号
 */
int josephus_circle(int n, int k, int m)
{
    // 处理边界情况：无人员时返回-1
    if(n <= 0)
    {
        printf("人数不能为0或负数！\n");
        return -1;
    }

    // 1. 构建循环链表
    Node *head = (Node *)malloc(sizeof(Node)); // 头节点（编号1）
    head->value = 1;
    head->next = NULL;
    Node *current = head;

    // 创建2~n号节点并连接
    for(int i = 2; i <= n; i++)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->value = i;
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }
    // 尾节点指向头节点，形成环
    current->next = head;

    // 2. 找到第k个节点的前驱（方便删除操作）
    Node *pre = head;
    // 移动k-2次，定位到第k个节点的前驱（k=1时，前驱是尾节点）
    for(int i = 0; i < k - 2; i++)
    {
        pre = pre->next;
    }

    // 3. 循环删除节点，直到只剩1个节点
    while(pre->next != pre)
    { // 只剩一个节点时，next指向自身
        // 数m-1次，找到要删除节点的前驱
        for(int i = 0; i < m - 1; i++)
        {
            pre = pre->next;
        }
        // 记录要删除的节点（用于释放内存）
        Node *del_node = pre->next;
        printf("出列：%d\n", del_node->value);
        // 删除节点：跳过要删除的节点
        pre->next = del_node->next;
        // 释放被删除节点的内存，避免内存泄漏
        free(del_node);
        del_node = NULL;
    }

    // 记录最后存活的编号，并释放最后一个节点的内存
    int survivor = pre->value;
    free(pre);
    pre = NULL;

    return survivor;
}

// 主函数测试
int main()
{
    // 测试用例：5个人，从第1个开始报数，数到3出列
    int survivor = josephus_circle(5, 1, 3);
    if(survivor != -1)
    {
        printf("最后存活的人编号：%d\n", survivor);
    }
    return 0;
}
