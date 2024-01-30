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
    
    int maxPathfromRoot(TreeNode* root, int &maxSum){
        if(!root) return 0;

        int lSum = max(maxPathfromRoot(root->left,maxSum),0);
        int rSum = max(maxPathfromRoot(root->right,maxSum),0);

        maxSum = max(maxSum,root->val+lSum+rSum);

        return root->val + max(lSum,rSum);
    }



    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;

        maxPathfromRoot(root,maxSum);
        return maxSum;

    }
};