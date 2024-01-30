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
    
    int height;
    
    int findHeight(TreeNode* root){
        if(!root) return 0;
        
        return 1+max(findHeight(root->left),findHeight(root->right));
    }
    void levelOrder(TreeNode* root,int level,vector<vector<int>>&v){
        if(!root) return;
        if(level>=v.size()) v.push_back(vector<int>());
        
        v[height-level-1].push_back(root->val);
        levelOrder(root->left,level+1,v);
        levelOrder(root->right,level+1,v);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        height = findHeight(root);
        vector<vector<int>>v(height);
        if(!root) return v;
        levelOrder(root,0,v);
        return v;   
    }
};