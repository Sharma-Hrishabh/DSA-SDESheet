/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs(TreeNode* root, vector<int>path,int B,vector<int>&ans){
    if(!root) return;
    
    path.push_back(root->val);
    if(root->val==B){
        ans=path;
        return;
    }
    
    dfs(root->left,path,B,ans);
    dfs(root->right,path,B,ans);
    
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>path;
    vector<int>ans;
    dfs(A,path,B,ans);
    return ans;
}
