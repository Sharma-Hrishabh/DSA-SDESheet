
class Solution {
public:

    class compare
    {
        public:
        bool operator()(ListNode*a, ListNode*b)
        {
            return a->val > b->val;    
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

//        priority_queue<ListNode*,vector<ListNode*>,greater<ListNode*>>pq;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i=0;i<lists.size();i++){c
            if(lists[i]!=NULL) pq.push(lists[i]);   
        }
        
        ListNode* head=NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            if(curr->next!=NULL){
                pq.push(curr->next);
            }

            // where to attach curr node

            if(head==NULL) {
                head=curr;
                tail=curr;
            }
            else{
                tail->next = curr;
                tail=curr;
            }
        }

        return head;

    }
};

