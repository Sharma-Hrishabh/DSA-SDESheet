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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* lHead = NULL;
        ListNode* geHead = NULL;
        // the other way would be to initliase them with a dummy node, in that case the head of result would be next of dummy node

        ListNode* l = lHead;
        ListNode* ge = geHead;

        
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->val < x){
                if(lHead !=NULL){
                    l->next = curr;
                    l = l->next;
                }
                else {
                    lHead = curr;
                    l = lHead;
                }
            }
            else{
                if(geHead != NULL){
                    ge->next = curr;
                    ge = ge->next;
                }
                else{
                    geHead=curr;
                    ge = geHead;
                }
            }
            curr = curr->next;
        }
        
        // terminate list
        if(lHead==NULL) {
            ge->next=NULL;
            return geHead;
        }
        else if(geHead == NULL){
            l->next = NULL;
            return lHead;
        } 
        else{
        ge->next = NULL;
        l->next = geHead;
        return lHead;
        }
    }
};