//O(N^2)
class Solution {
public:
    ListNode* rotateOne(ListNode* head){
        ListNode* curr = head;
        ListNode* prev=NULL;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=NULL;
        curr->next=head;
        return curr;
    }
    int length(ListNode* head){
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        return 1+length(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        int l = length(head);
        ListNode* curr=head;
        k=k%l;
        while(k--){
            curr=rotateOne(curr);
        }
        return curr;

    }
};

//O(N)
class Solution {
public:

    int length(ListNode* head){
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        return 1+length(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        int l = length(head);
        k= k % l;
        if(k==0) return head;
        int cut = l-k;
        ListNode* newTail=NULL;
        ListNode* newHead=NULL;
        ListNode* curr=head;
        while(curr->next!=NULL){
            if(cut==1){
                newTail=curr;
                newHead=curr->next;
            }
            cut--;
            curr=curr->next;
        }
        //make circular
        curr->next=head;

        //make cut
        newTail->next=NULL;

        return newHead;
    }
};