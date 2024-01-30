#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// O(N^2)
class Solution {
public:

    int maxValue(TreeNode* root){
        if(!root) return INT_MIN;
        while(root->right!=NULL){
            root = root->right;
        }
        return root->val;
    }

    int minValue(TreeNode* root){
        if(!root) return INT_MAX;
        while(root->left!=NULL){
            root = root->left;
        }
        return root->val;

    }


    bool isValidBST(TreeNode* root) {

        if(!root) return true;

        if(maxValue(root->left)>root->val) return false;

        if(minValue(root->right)<root->val) return false;

        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;

        return true;
    

    }
};


int main(){
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout<<s.isValidBST(root)<<endl;
    return 0;
}



// O(N)

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


class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;
        if (root.val >= maxVal || root.val <= minVal) return false;
        return isValidBST(root.left, minVal, root.val) && isValidBST(root.right, root.val, maxVal);
    }
}