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
    void dfs(TreeNode* root,int sum,int targetSum,vector<vector<int>>&paths,vector<int>&path){
        if(!root) return;
        
        sum += root->val;
        
        if(!root->left && !root->right && sum==targetSum) {
            paths.push_back(path);
            return;
        }
        if(root->left)
        { 
            path.push_back(root->left->val);
            dfs(root->left,sum,targetSum,paths,path);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            dfs(root->right,sum,targetSum,paths,path);
            path.pop_back();
        }
        
        
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>paths;
        
        if(!root) return paths;
        
        vector<int>path;
        path.push_back(root->val);
        
        dfs(root,0,targetSum,paths,path);
        
        return paths;
        
    }
};



