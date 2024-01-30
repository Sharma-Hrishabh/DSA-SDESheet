// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
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

/*
The ideas is to keep a tail pointer at each list and compare the values at the pointers.
First set head from the lists whichever is smaller.
Then keep a tail pointer at the head and keep moving the tail pointer to the next node.

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode* head = NULL;

    if(list1==NULL) return list2;
    if(list2==NULL) return list1;

    if(list1->val<=list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }

    ListNode* tail =  head;

    ListNode* temp =NULL;
    while(list1!=NULL && list2!=NULL){

        if(list1->val<=list2->val){
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp = list2;
            list2 = list2->next;
        }
        // Assign the temp(smaller) to the tail
        tail->next = temp;
        // Update the tail with new node.
        tail = temp;
    }

    if(list1==NULL) tail->next = list2;
    else tail->next = list1;

    return head;
    }
};

// If value of head1 is less then head2 then add head1 to the result and move head1 to next node, and asking recusrsion to share the remaining merged list, and vice-versa.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val<=list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
    }
};