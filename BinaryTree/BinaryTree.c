#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;

}BTNode;

BTNode* BuyNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if(node == NULL)
    {
        perror("malloc failed");
        return 0;
    }
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BTNode* CreatTree()
{
    BTNode* node1 = BuyNode(1);
    BTNode* node2 = BuyNode(2);
    BTNode* node3 = BuyNode(3);
    BTNode* node4 = BuyNode(4);
    BTNode* node5 = BuyNode(5);
    BTNode* node6 = BuyNode(6);
    
    node1->left = node2;
    node1->right = node4;

    node2->left = node3;

    node4->left = node5;
    node4->right = node6;

    return node1;
}

void PerOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return ;
    }

    printf("%d ",root->data);
    PerOrder(root->left);
    PerOrder(root->right);
}

void InOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return ;
    }

    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return ;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

//节点的个数
//但是在这里有个问题,除了第一次使用，后面每次使用时都要先初始化再使用
// int size = 0;
// void TreeSize(BTNode* root)
// {
//     if(root == NULL)
//     {
//         return ;
//     }
//     ++size;
//     TreeSize(root->left);
//     TreeSize(root->right);
// }

int TreeSize(BTNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left)+TreeSize(root->right)+1;
}

// int TreeHeight(BTNode* root)
// {
//     if(root == NULL)
//     {   
//         return 0;
//     }
//     return  TreeHeight(root->left) > TreeHeight(root->right) 
//             ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
// }
int TreeHeight(BTNode* root)
{
    if(root == NULL)
    {   
        return 0;
    }
    int leftHeight = TreeHeight(root->left);
    int rightHeight = TreeHeight(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
//小小的进阶一下
//求第K层的节点的个数
int TreeLevel(BTNode* root, int k)
{
    if(root == NULL)
    {
        return 0;
    }

    if(k == 1)
    {
        return 1;
    }

    int leftK = TreeLevel(root->left, k-1);
    int rightK = TreeLevel(root->right, k-1);

    return leftK + rightK;
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == x)
    {
        return root;
    }
    BTNode* lret = BinaryTreeFind(root->left, x);
    if(lret)
    return lret;
    BTNode* rret = BinaryTreeFind(root->right, x);
    if(rret)
    return rret;

    return NULL;
}
#include "Queue.h"
//层序
void LevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if(root != NULL)
    {
        QueuePush(&q, root);
    }
    while(!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", front->data);

        if(front->left)
        {
            QueuePush(&q, front->left);
        }
        if(front->right)
        {
            QueuePush(&q, front->right);
        }
    }

    QueueDestroy(&q);
}

int main()
{
    BTNode* root = CreatTree();
    PerOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");

    LevelOrder(root);
    return 0;
}