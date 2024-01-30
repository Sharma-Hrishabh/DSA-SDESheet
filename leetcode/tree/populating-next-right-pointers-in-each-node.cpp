/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// Approach-1 : BFS
// O(N)
// S(N)
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        
        queue<Node*>q;
        q.push(root);
        Node* prev;
        while(!q.empty()){
            int n = q.size();
            prev=NULL;
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if(prev!=NULL) prev->next = temp;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                prev=temp;
            }
            
        }
        
        return root;
    }
};


//Approach-2 : DFS
// O(N)
// S(1)


class Solution {
public:
    
    Node* connect(Node* root) {
        if(root==NULL) return root;
        
        if(root->left) root->left->next = root->right;
        
        if(root->right && root->next) root->right->next=root->next->left;
 
 
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
