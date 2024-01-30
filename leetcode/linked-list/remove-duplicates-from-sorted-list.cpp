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
    ListNode* deleteDuplicates(ListNode* head) {
                unordered_set<int>s;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){

            auto itr = s.find(curr->val);
            if(itr!=s.end()){
                //remove the node  
                prev->next= curr->next;
                curr->next=NULL;
                curr=prev->next;
            }
            else {
                s.insert(curr->val);
                prev=curr;
                curr=curr->next;   
            }
        }
        
        return head;
    }
};