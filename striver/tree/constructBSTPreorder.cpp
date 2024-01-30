#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    TreeNode* insertNode(TreeNode* root,int val){
        // if(!root) return new TreeNode(val);
        // base case
        if(val>root->val) return insertNode(root->right,val);
        return insertNode(root->left,val);

        if(!root) {
            if(val>root->val) root->right = new TreeNode(val);
            else root->left = new TreeNode(val);
            return root;
        }
        
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curr = root;
        for(int i=1;i<n;i++){
            if(preorder[i]>preorder[i-1]){
                // check from start for insertion
                // where to attch this node
                curr = insertNode(root,preorder[i]);
            }
            else{
                // keep inserting
                if(preorder[i]<curr->val) {
                    curr->left = new TreeNode(preorder[i]);
                    curr=curr->left;
                }
                else{
                    curr->right = new TreeNode(preorder[i]);
                    curr=curr->right;
                }
            }
        } 
        return root;
    }

};


void lot(TreeNode* root){
    if(!root) return;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<endl;
    }

}

int main(){
    Solution s;
    vector<int> preorder;
    // = {8,5,1,7,10,12};
    preorder.push_back(8);
    preorder.push_back(5);
    preorder.push_back(1);
    preorder.push_back(7);
    preorder.push_back(10);
    preorder.push_back(12);

    TreeNode* root = s.bstFromPreorder(preorder);
    lot(root);
    return 0;
}





// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& A) {
//         int i = 0;
//         return build(A, i, INT_MAX);
//     }

//     TreeNode* build(vector<int>& A, int& i, int bound) {
//         if (i == A.size() || A[i] > bound) return NULL;
//         TreeNode* root = new TreeNode(A[i++]);
//         root->left = build(A, i, root->val);
//         root->right = build(A, i, bound);
//         return root;
//     }
// };