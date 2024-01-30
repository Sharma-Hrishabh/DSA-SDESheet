/**
 * Definition for singly-linked list.

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
#include<iostream>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    

    ListNode* reverseList(ListNode* head)
    {
        if (head->next == NULL)
            return head;
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
  
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     ListNode* next = NULL;
    //     while( curr !=NULL){
    //         next = curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=next;
    //     }
    //     return prev;
    // }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* temp = s.reverseList(head);
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;    
}