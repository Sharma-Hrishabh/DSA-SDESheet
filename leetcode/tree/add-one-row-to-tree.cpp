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
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        
        if(depth==1) {
            TreeNode* l = new TreeNode(val,root,NULL);              
            return l;
        }
        
        
        if(depth==2) {
            // attach the new row
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            TreeNode* l = new TreeNode(val,left,NULL);
            TreeNode* r = new TreeNode(val,NULL,right);
            
            root->left=l;
            root->right=r;
            
            return root;
            
        }
        
        root->left = addOneRow(root->left,val,depth-1);
        root->right = addOneRow(root->right,val,depth-1);
        
        return root;
    }
};