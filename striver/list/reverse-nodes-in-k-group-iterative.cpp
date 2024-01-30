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
    int length(ListNode* head){
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        return 1+length(head->next);    
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL) return NULL;
        if(length(head)==1) return head;
        if(length(head)<k) return head;
        if(k==1) return head;
        ListNode* ans;

        
        int count=length(head);
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        ListNode* oldHead=NULL;

        while(count>=k){


            ListNode* start=curr;
            
            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }

            count-=k;

            // connect oldHead of prev loop to new Head of current loop
            if(oldHead!=NULL){
                oldHead->next=prev;
            }
            else{
                ans=prev;
            }

            oldHead=start;


        }
        
        // vert important for last group
        if(curr!=NULL) oldHead->next=curr;
        else oldHead->next=NULL;
        
        return ans;
        
    }
};


int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* temp = s.reverseKGroup(head,2);
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}