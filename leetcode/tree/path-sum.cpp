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
    bool hasPathSum(TreeNode* root, int targetSum) {
        

        if(!root) return false;
        
        targetSum -= root->val;
            
        if(!root->left && !root->right && targetSum==0) return true;
            
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
        
    }
};


class Solution {
public:
    
    void dfs(TreeNode* root,int sum,int targetSum,bool &ans){
        if(!root) return;
        
        sum += root->val;
        
        if(!root->left && !root->right && sum==targetSum) {
            ans=true;
            return;
        }
        
        dfs(root->left,sum,targetSum,ans);
        dfs(root->right,sum,targetSum,ans);
        
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        //if(!root && targetSum==0) return true;
        
        if(!root) return false;

        bool ans= false;
        
        dfs(root,0,targetSum,ans);
        
        return ans;
        
    }
};