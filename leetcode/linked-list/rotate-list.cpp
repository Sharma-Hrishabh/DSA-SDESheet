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
        if(!head) return 0;
        return 1+length(head->next);
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n = length(head);
        if(n==0) return NULL;
        k = k%n;
        if(n==1) return head;
        ListNode* temp;
        while(k--){
            //rotate 1
            cout<<"For k: "<<k<<endl;
            temp = head;
            
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            cout<<temp->val<<endl;
            
            // link last node with old head
            temp->next->next = head;
            // update head
            head = temp->next;
            // break temp
            temp->next=NULL;
            
        } 
        return head;        
        
    }
};