/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void solve(TreeNode* root){
        if(root!=NULL){
            solve(root->left);
            ans.push_back(root->val);
            solve(root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};


class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*>s;
        vector<int>ans;
       s.push(root);
       while(1){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            if(s.size()==0) return ans;
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            root = temp->right;
        }
       }

    }
};


