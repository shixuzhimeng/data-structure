#include <stdio.h>
#include <stdlib.h>

// 定义单向循环链表节点
struct Node {
    int data;
    struct Node* next;
};

// 创建一个新的节点
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // 初始时节点的next指向自己
    return newNode;
}

// 插入节点到链表头部
void insertHead(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// 插入节点到链表尾部
void insertTail(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while(temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// 任意位置插入节点
void insertAtPosition(struct Node** head, int value, int position)
{
    if(position == 1)
    {
        insertHead(head, value);
        return;
    }
    
    struct Node* newNode = createNode(value);
    struct Node* temp = *head;
    int count = 1;

    // 遍历到插入位置的前一个节点
    while(temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
        if (temp == *head) break;
    }

    if(temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Invalid position\n");
    }
}

// 删除头节点
void deleteHead(struct Node** head)
{
    if(*head == NULL) return;
    if((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node* temp = *head;
        struct Node* last = *head;
        while(last->next != *head)
        {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// 删除尾节点
void deleteTail(struct Node** head)
{
    if(*head == NULL) return;
    if((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while(temp->next != *head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

// 删除任意位置的节点
void deleteAtPosition(struct Node** head, int position)
{
    if(*head == NULL)
        return;
    if(position == 1)
    {
        deleteHead(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;

    // 遍历到删除位置的前一个节点
    while(temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->next;
        count++;
        if (temp == *head) break;
    }


    if(temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Invalid position\n");
    }
}

// 遍历链表并打印
void display(struct Node* head)
{
    if(head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("\n");
}
//查找
int search(struct Node* head, int value)
{
    if(head == NULL) return 0;
    struct Node* temp = head;
    do
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    while(temp != head);
    return 0;
}