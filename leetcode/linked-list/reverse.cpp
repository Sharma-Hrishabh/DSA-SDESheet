/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Function to reverse a given Linked List using Recursion


/*
1->2->3->4->5->NULL

1 -> recursion of 2->3->4->5->NULL
1   ->     2 <- 3 <- 4 <- 5
head->next->next = head;    // 1->next->next = 1   ; link 2->1
head->next = NULL;          // 1->next = NULL;      ; break 1->2
return the new head of the reversed list
*/

Node* reverseList(Node* head)
{
    if (head->next == NULL)
        return head;
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
  

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while( curr !=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};