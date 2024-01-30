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



 /*
Approach:

Preorder : 3 9 20 15 7
Inorder : 9 3 15 20 7


- First index of preorder will be the root node.
- Now if you find the position of root node in inorder. All the values to left of the position will be in left subtree and to the right will be in right subtree.
- We need the postorder for left and right subtree.
- Count the no of elements in left subtree(from inorder), after the root node in preorder, pick the elements equal to count of elements in subtree, that will be the preorder of left subtree 
    and the remaining elements in preorder will be the preorder of right subtree.
- We can apply recursion on left and right subtree with their preorder and inorder . 

O(n)
S(n)
 */
class Solution {
public:
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,   unordered_map<int,int>&mp){

        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inorderRootIndex = mp[root->val];
        
        int leftElement = inorderRootIndex-inStart;
        
        root->left = buildTree(preorder,preStart+1,preStart+leftElement,inorder,inStart,inorderRootIndex-1,mp);
        root->right = buildTree(preorder,preStart+leftElement+1,preEnd,inorder,inorderRootIndex+1,inEnd,mp);
        
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        
        
    }
};