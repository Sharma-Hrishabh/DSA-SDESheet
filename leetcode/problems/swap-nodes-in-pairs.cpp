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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* newHead = NULL;
        
        if(head==NULL || head->next==NULL) return head;
        
        newHead = head->next;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL && curr->next!=NULL){
            ListNode* temp = curr->next;
            curr->next=curr->next->next;
            temp->next=curr;
            if(prev!=NULL) prev->next=temp;
            //iterate
            prev=curr;
            curr=curr->next;
            //prev=prev->next->next;
        }
        
        return newHead;
    }
};