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
class Solution {
public:
    void reverseList(ListNode* &head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while( curr !=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
    }
    
    void pr(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        if(head->next==NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev=NULL;
        
        while(fast != NULL && fast->next!=NULL ){
            prev = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        // if fast is not null then odd no. of elements, so we have to advacne the pointer to reverse the list
        if(fast!=NULL) slow=slow->next;
        reverseList(slow);
        while(head!=NULL && slow!=NULL){
            if(head->val!=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;        
    }
};