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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;


        int carry = 0 ;
        int sum=0;
        ListNode* ans = NULL;
        ListNode* head=NULL;
        while(l1!=NULL && l2!=NULL){
            sum = l1->val + l2->val + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            
            if(!ans){
                ans = new ListNode(sum);
                head=ans;
            }
            else{
                ListNode* temp = new ListNode(sum);
                ans->next = temp;
                ans=ans->next;
            }
            l1=l1->next;
            l2=l2->next;
        }

        while(l1!=NULL){
            sum=l1->val+carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            ans->next=temp;
            ans = ans->next;
            l1=l1->next;
        }

        while(l2!=NULL){
            sum=l2->val+carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            ans->next=temp;
            ans = ans->next;
            l2=l2->next;
        }


        if(carry){
            ListNode* temp = new ListNode(carry);
            ans->next = temp;
            ans = ans->next;
        }


        return head;


    }
};

int main(){
    
}  