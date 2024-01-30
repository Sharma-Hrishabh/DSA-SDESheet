class Solution {
public:

    void solve(TreeNode* root, int k,int &count,int &ans){
        if(count>k) return;
      
        if(root->left) solve(root->left,k,count,ans);
        
        count++;
        if(k==count) {
            ans=root->val;
        } 
        
        if(root->right) solve(root->right,k,count,ans);


    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        solve(root,k,count,ans);
        return ans;

    }
};