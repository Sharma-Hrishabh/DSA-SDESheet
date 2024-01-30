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

// minDepth will be the minimum of the left and right subtree's minDepth plus 1. If the node is a leaf node, then the minDepth is 1.

/// if a  leaf node, check its level is minimum or not while doing a DFS


class Solution {
public:
    
    int mindepth=INT_MAX;
    
    void dfs(TreeNode* root,int depth){
        
        if(!root) return;
        
        if(root->left==NULL && root->right==NULL) {
            
            if(depth<mindepth) mindepth = depth;
            return;
        }
        depth++;
        dfs(root->left,depth);
        dfs(root->right,depth);
        
        
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        
        dfs(root,1);
        
        
        if(mindepth<INT_MAX) return mindepth;
        else return 0;
        
     }
};


class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        if(!root->left && !root->right) return 1;

        // while comparing min, the l r should be initialised with something
        int l = INT_MAX, r = INT_MAX;

        // If left subtree is not NULL, recur for left subtree
        if (root->left)
        l = minDepth(root->left);

        // If right subtree is not NULL, recur for right subtree
        if (root->right)
        r =  minDepth(root->right);

        //height will be minimum of left and right height +1
        return min(l , r) + 1;

     }
};