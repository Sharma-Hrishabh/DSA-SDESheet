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
        unordered_map<int,int>mp;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){

            auto itr = mp.find(curr->val);
            if(itr!=mp.end()){
                //remove the node  
                itr->second=1;
                prev->next= curr->next;
                curr->next=NULL;
                curr=prev->next;
            }
            else {
                mp.insert(make_pair(curr->val,0));
                prev=curr;
                curr=curr->next;   
            }
        }
        
        curr=head;
        prev=NULL;
        while(curr!=NULL){
            auto itr = mp.find(curr->val);
            if(itr!=mp.end() && itr->second==1){
                // Duplicate 
                if(prev==NULL){
                    //first node
                    head=curr->next;
                    curr=curr->next;
                    
                }
                else if(curr->next==NULL){
                    //last Node
                    prev->next=NULL;
                    curr=curr->next;
                    
                }
                else{
                    // in between
                    prev->next=curr->next;
                    // curr->next=NULL;
                    curr= prev->next;
                }
                
            }
            else{
                //Non-duplicate
                prev=curr;
                curr=curr->next;   
            }
            
        }
        
        return head;        
    }
};