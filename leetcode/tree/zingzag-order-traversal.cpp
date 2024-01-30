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

//  The idea is to keep a flag for directiom , and just place the values at right index as per the direction flasg.
// O(N)
// S(N)
class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                
                TreeNode* node;
                node = q.front();
                q.pop();
                

                if(leftToRight){
                    v[i] = node->val;
                }
                else {
                    v[n-i-1] = node->val;
                }
 
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
 
            }
            ans.push_back(v);
            leftToRight=!leftToRight;

            }
        
            return ans;
    }
           
     
};