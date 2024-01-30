/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        //step-1 create copy nodes
        Node* itr=head;
        Node* front=NULL;
        while(itr!=NULL){
            front=itr->next;
            Node* copy = new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }

        //step-2 duplicate random pointers
        itr=head;
        while(itr!=NULL){
            if(itr->random!=NULL) itr->next->random = itr->random->next;
            itr=itr->next->next;
        }

        //step-3 extract copy list

        Node* newHead = NULL;
        Node* newTail=NULL;
        front = NULL;
        itr=head;
        while(itr!=NULL){
            front = itr->next->next;
            if(newHead==NULL){
                // head not set
                newHead = itr->next;
                newTail=newHead;
            }
            else{
                newTail->next=itr->next;
                newTail=newTail->next;
            }
            //correct original list next pointer
            itr->next=front;
            itr=itr->next;
        } 

        return newHead;
        
    }
};