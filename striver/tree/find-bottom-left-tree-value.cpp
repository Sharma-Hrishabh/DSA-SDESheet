class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;

        int lH = height(root->left);
        int rH = height(root->right);

        return 1+max(lH,rH);
    }

    void solve(TreeNode* root, int level,int &ans){
        if(level==1 && root!=NULL) {
            ans=root->val;
            return;
        }

        if(root->right)  solve(root->right,level-1,ans);
        if(root->left)  solve(root->left,level-1,ans);

    }

    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);

        int ans;
        solve(root,h,ans);
        return ans;

    }
};