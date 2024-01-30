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
    
    vector<TreeNode*> genBST(int start,int end){
        vector<TreeNode*>ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        // Pick one node as root iteratively
        for(int i=start;i<=end;i++){
            //the left subtree can be gen with nodes value less than i and right with value greater than i.
            vector<TreeNode*> leftSubtrees = genBST(start,i-1);
            vector<TreeNode*> rightSubtrees = genBST(i+1,end);            
        
            //conenct all the possible combinations of left and right subtree with the ith node as root and push ith node as root to ans array
            for(int j=0;j<leftSubtrees.size();j++){
                TreeNode* left = leftSubtrees[j];
                for(int k=0;k<rightSubtrees.size();k++){
                    TreeNode* right = rightSubtrees[k];
                    
                    TreeNode* root = new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                    
                }
            }
        
        }
        
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
       
        vector<TreeNode*> ans;
        if(n==0) return ans;
        
        ans = genBST(1,n);
        
        return ans;
        
    }
};