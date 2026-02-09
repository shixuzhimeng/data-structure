#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;

typedef struct Node {
    SListDataType x;
    struct Node* next;
}SLNode;

SLNode* CreatNode(SListDataType x) {
    SLNode* newNode  = (struct Node*)malloc(sizeof(struct Node));
    if(newNode = NULL) {
        perror("malloc failed");
        return ;
    }
    newNode->x = x;
    newNode->next = NULL;
}

void PushBack(SLNode** head, SListDataType x) {
    SLNode* newNode = CreatNode(x);
    if(*head == NULL) {
        *head = newNode;
    } else {
        SLNode* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void PopBack(SLNode** head) {
    if(*head == NULL)
    {
        return ;
    }
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        SLNode* tail =*head;
        while(tail->next != NULL && tail->next->next != NULL)
        {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}