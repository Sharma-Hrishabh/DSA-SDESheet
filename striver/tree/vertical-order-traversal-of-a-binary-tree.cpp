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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map < int, multiset < int >>> mp;


        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
        int l=0;
        while(!q.empty()){            
            int n = q.size();

            for(int i=1;i<=n;i++){
                pair<TreeNode*,int>p = q.front();
                q.pop();
                int d = p.second;
                TreeNode* node = p.first;
                mp[d][l].insert(node->val);
                
                if(node->left) q.push(make_pair(node->left,d-1));
                if(node->right) q.push(make_pair(node->right,d+1));
            }
            l++;
        }


        vector<vector<int>>ans;
        for(auto d=mp.begin();d!=mp.end();d++){
            map<int,multiset<int>>s = d->second;
            vector<int>v;
            for(auto i = s.begin();i!=s.end();i++){
                multiset<int>t = i->second;
                for(auto j=t.begin();j!=t.end();j++){
                  v.push_back(*j);
                }
            }
            ans.push_back(v);
        }
        return ans;

    }
};