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
    
    void swapNodes(ListNode** head,ListNode* head1,ListNode* prevHead1,ListNode* head2,ListNode* prevHead2){
        
        
                
        if(prevHead1!=NULL) prevHead1->next = head2;
        else *head = head2;
        
        
        ListNode* nextHead2 = head2->next;
        head2->next = head1 - >next;
        head1->next = nextHead2;
        
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* prevUnsortedHead = NULL;
        while(firstUnSortedHead->next!=NULL){
            ListNode* prevCurr = firstUnSortedHead;
            ListNode* curr = firstUnSortedHead->next;
            while(curr!=NULL){
                if(curr->val<firstUnSortedHead->val){

                    // swap the nodes
                    swapNodes(&head,&firstUnSortedHead,&prevUnsortedHead,&curr,&prevCurr);
                    
                    prev=curr;
                    curr=curr->next;
                }
            }
            prevUnsortedHead = firstUnSortedHead;
            firstUnSortedHead = firstUnSortedHead->next;
        }
        
        //return the head
        return head;
        
    }
};