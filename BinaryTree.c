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

int main()
{
    BTNode* root = CreatTree();
    PerOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    return 0;
}