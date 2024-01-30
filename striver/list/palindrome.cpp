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

    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        int l = length(head);
        ListNode* mid = findMid(head);

        if(l==1) return true;
        ListNode* curr;
        if(l%2==0){
            curr=mid;
        }
        else{
            curr=mid->next;
        }

        //reverse
        //ListNode* curr=mid->next;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        //disconnect from mid
        //mid->next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        mid->next=prev;

        if(l%2!=0) mid=mid->next;

        while(head!=NULL && mid!=NULL){
            if(head->val!=mid->val) return false;
            head=head->next;
            mid=mid->next;
        }

        return true;
    
    }
};


int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
   // head->next->next->next->next = new ListNode(1);
    Solution s;
    cout<<s.isPalindrome(head);
    return 0;
}