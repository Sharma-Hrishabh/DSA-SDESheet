// O(N^2)

class Solution {
public:
    
    int height(TreeNode* root){
        if(!root) return 0;
        
        return 1+max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l-r)>1) return false;
    
        return isBalanced(root->left) && isBalanced(root->right);
    
    }
};


//O(N)

class Solution {
public:
    
    int height(TreeNode* root,bool &balanced){
        if(!root) return 0;
        
        int  l = height(root->left,balanced);
        int  r = height(root->right,balanced);

        if(abs(l-r)>1) {
            balanced = false;
        }

        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool balanced = true;
        height(root,balanced);
        if(!balanced) return false;
        
        return true;    
    }
};
