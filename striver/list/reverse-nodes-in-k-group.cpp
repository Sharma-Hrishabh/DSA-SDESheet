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
        else return 1+length(head->next);
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        if(length(head)<k) return head;
        
        ListNode *curr,*prev,*next;
        
        curr = head;
        prev=NULL;
        next=NULL;
        
        for(int i=0;i<k;i++){
            
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        
        head->next = reverseKGroup(curr,k);
        
        return prev;
    }
};





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

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = length(head);

        int groups = n/k;

        int nHead = groups;

        ListNode* newHead;

        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* next = NULL;
        
        while(groups){
            ListNode* start=curr;
            ListNode* lastPrev = prev;
            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next = prev;
                prev=curr;
                curr=next;
            }
            if(nHead==groups) newHead = prev;

            start->next=curr;
            //conect last prev with new prev
            if(lastPrev!=NULL) lastPrev->next = prev;
            //udpate new prev
            prev=start;

            
            groups--;
            
        }

        return newHead;
    }
};