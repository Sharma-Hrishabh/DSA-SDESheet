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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        queue<pair<int,TreeNode*>>q;
        q.push(make_pair(0,root));
        map<int,int>mp;
       // mp.insert(make_pair(0,root->val));
        int flag=0;
        while(!q.empty()){
            for(int i = q.size();i>0;i--){
                pair<int,TreeNode*> temp = q.front();
                if(temp.first<0){
                    mp.insert(make_pair(temp.first,temp.second->val));
                }
                else if(temp.first>0) {
                    auto itr = mp.find(temp.first*-1);
                    if(itr==mp.end()) return false;
                    if(itr->second != temp.second->val) {
                        return false;
                    }
                    else{
                        mp.erase(itr);
                    }
                }
                else {
                    if(flag==0 && temp.second!=root){
                         mp.insert(make_pair(temp.first,temp.second->val));
                        flag=1;
                    }
                    else if(flag==1 && temp.second!=root){
                        auto itr = mp.find(temp.first);
                        if(itr==mp.end()) return false;
                        else mp.erase(itr);
                    }
                    else{
                        
                    }
                    
                }
                //if(temp.first!=0) 
                q.pop();
                
                if(temp.second->left) q.push(make_pair(temp.first-1,temp.second->left));
                if(temp.second->right) q.push(make_pair(temp.first+1,temp.second->right)); 
                
            }
        }
        if(mp.size()!=0) return false;
        return true;
    }
};