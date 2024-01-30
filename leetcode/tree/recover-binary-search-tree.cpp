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
Approach-1: Generate inorder traversal, sort it, and again do inorder and keep replacing the incorrect values.\
O(2N+NlogN)
S(N)
*/
class Solution {
public:
    vector<int> it;
    int counter=0;
    void inorder(TreeNode* root,bool compareMode){
        if(root!=NULL){
            
            inorder(root->left,compareMode);
            if(compareMode==true){
                if(it[counter]!=root->val) root->val=it[counter];
                counter++;
            }
            else it.push_back(root->val);
            inorder(root->right,compareMode);
            
        }
    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root,false);
        
        sort(it.begin(),it.end());
        
        inorder(root,true);
        
        
    }
};

/*
Approach-2:
 While doing inorder traversal, if we encounter any value which is less than prev value, then that position is incorrect. Keep the pair in first & mid .
 If you reach any value which is also inccorect and prev > current, make it last.
 So there will be two cases if the swapped nodes are adjacent, last will never be set and you can swap first & mid else swap first and last
 O(N)
 S(1)

*/

class Solution {
public:
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    
    void inorder(TreeNode* root){
        if(root!=NULL){
            
            inorder(root->left);
            
            
            if(prev!=NULL && prev->val > root->val){
                
                if(first==NULL){
                    first=prev;
                    mid=root;
                }
                else last=root;                
                
            }
            
            prev=root;
            
            inorder(root->right);
            
        }
    }
    
    void recoverTree(TreeNode* root) {
        first=mid=last=prev=NULL;
        inorder(root);
        
        if(first && last){
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
            return;
        }
        
        if(first && mid){
            int temp = first->val;
            first->val = mid->val;
            mid->val = temp;
            return;
        }
        
        return;
    }
};