// /**
//  * Definition for a Node.
//  * struct Node {
//  *     int val;
//  *     struct Node *next;
//  *     struct Node *random;
//  * };
//  */

// struct Node* copyRandomList(struct Node* head) {
// 	struct Node* cur = head;
//     while(cur)
//     {
//         struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//         copy->val = cur->val;
//         struct Node* next = cur->next;

//         cur->next = copy;
//         copy->next = next;

//         cur = next;
//     }


//     cur = head;
//     while(cur)
//     {
//         struct Node* copy = cur->next;
//         if(cur->random == NULL)
//         {
//             copy->random = NULL;
//         }
//         else
//         {
//             copy->random = cur->random->next;
//         }

//         cur = cur->next->next;
//     }

//     struct Node* copyhead = NULL;
//     struct Node* copytail = NULL;
//     cur = head;
//     while(cur)
//     {
//         struct Node* copy = cur->next;
//         struct Node* next = copy->next;

//         if(copyhead == NULL)
//         {
//             copyhead = copytail = copy;
//         }
//         else
//         {
//             copytail->next = copy;
//             copytail = copytail->next;
//         }
//         cur->next = next;
//         cur = next;
//     }
//     return copyhead;
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow , *fast;
    slow = fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            struct ListNode* meet = slow;
            struct ListNode* start = head;
            while(meet != start)
            {
                meet = meet->next;
                start = start->next;
            }

            return meet;
        }
    }
    

    return NULL;
}