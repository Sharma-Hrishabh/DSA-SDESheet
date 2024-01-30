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

 // pick any two nodes in a level and between them nodes (null-nonnull)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
        int maxWidth=0;
        while(!q.empty()){
            int n = q.size();
            long l;
            long r;
            for(int i=1;i<=n;i++){
                pair<TreeNode*,long> fr = q.front();
                q.pop();

                if(i==1){
                    l=fr.second;
                }
                if(i==n){
                    r=fr.second;
                }

                long left = 2 * fr.second+1;
                long right = 2 * fr.second+2;
                if(fr.first->left!=NULL) q.push(make_pair(fr.first->left,left));
                if(fr.first->right!=NULL) q.push(make_pair(fr.first->right,right));
            }
            int temp = r-l+1;
            if(temp>maxWidth) maxWidth=temp;

        }
        return maxWidth; 
    }
};