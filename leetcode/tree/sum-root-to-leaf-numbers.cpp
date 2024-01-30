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
    void dfs(TreeNode* root,int currSum,int& ans){
        if(!root->left && !root->right) {
            ans+=currSum;
            return;
        }
        
        
        if(root->left) dfs(root->left,currSum*10+root->left->val,ans);
        if(root->right) dfs(root->right,currSum*10+root->right->val,ans);
    
    
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        int ans=0;
        
        dfs(root,root->val,ans);
        
        return ans;
        
        
    }
};