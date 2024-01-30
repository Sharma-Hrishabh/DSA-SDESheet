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


// Incorrect solution

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        // check left & right are correct
        if(root->left && root->val<=root->left->val) return false;
        if(root->right && root->val>=root->right->val) return false;  
        
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        
        return true;
    }
};


// Correct solution

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root,int min,int max) {
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        // The left subtree should have value less than the ultimate root node, and right subtree values should be greater.
        // So at each step we will look if the value of a node is less than the current max which can be one less than the val of root node.
        // Similarly we can check if the value is always greather than possible min in right subtree, which will be plus one to current node.
        return isValidBSTHelper(root->left,min,root->val-1) && isValidBSTHelper(root->right,root->val+1,max);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return isValidBSTHelper(root,INT_MIN,INT_MAX);
    }
};


// Solution 2

// In this solution we are just propogating the range in which a value should lie.
// for every left movement we will set the max as root node [r], and for every right movement, we will set min as root node [l] . The value of a node should always lie in this range.
class Solution {
public:
    bool isValidBSTHelper(TreeNode* root,TreeNode* l=NULL,TreeNode* r=NULL) {
        if(!root) return true;

        if(!l && root->val>=l->val) return false;
        if(!r && root->val<=r->val) return false;
        
        return isValidBSTHelper(root->left,l,root) && isValidBSTHelper(root->right,root,r);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return isValidBSTHelper(root,NULL,NULL);
    }
};


class Solution {
public:
    bool isValidBSTHelper(TreeNode* root,TreeNode* l=NULL,TreeNode* r=NULL) {
        if(!root) return true;

        if(l!=NULL && root->val<=l->val) return false;
        if(r!=NULL && root->val>=r->val) return false;
        
        return isValidBSTHelper(root->left,l,root) && isValidBSTHelper(root->right,root,r);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return isValidBSTHelper(root);
    }
};