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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        if(!root) return v;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>temp;
            for(int i = q.size();i>0;i--){
            TreeNode* f = q.front();
            temp.push_back(f->val);
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            } 
            v.push_back(temp);
        }
        return v;
    }
};

// Recursive
class Solution {
public:
    void levelOrder(TreeNode* root,int level,vector<vector<int>>&v){
        if(!root) return;
        if(level>=v.size()) v.push_back(vector<int>());
        v[level].push_back(root->val);
        levelOrder(root->left,level+1,v);
        levelOrder(root->right,level+1,v);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        if(!root) return v;
        levelOrder(root,0,v);
        return v;
    }
};