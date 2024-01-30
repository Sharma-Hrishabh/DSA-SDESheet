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
    int length(ListNode* head){
        if(head==NULL) return 0;
        else return length(head->next)+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = length(head);
        int x = l-n+1;
        int count=1;
        ListNode* temp = head;
        
        // if node is of single length
        if(l==1) return NULL;

        //if node to delete is head;
        if(l==n) return head->next;
                
        while(count!=l){
            if(count==x-1){
                break;
            }
            temp=temp->next;

            count++;
        }

        
        // if node to delete is tail
        if(l==x) temp->next=NULL;
        else temp->next = temp->next->next;
        
        return head;
        
        
    }
};