#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class Solution {
  public:
  
    void solve(Node* root,int d, map<int,pair<int,int> >&mp,int level){
        if(!root) {
            return;
        }
        else{
            auto itr = mp.find(d);
            if(itr==mp.end()) {
                mp.insert(make_pair(d,make_pair(level,root->data)));
            }
            else if(level<itr->second.first) {
                mp[d].first=level;
                mp[d].second=root->data;
            }
        }   
        solve(root->left,d-1,mp,level+1);
        
        solve(root->right,d+1,mp,level+1);

    }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, pair<int, int> >mp;
        
        solve(root,0,mp,0);
        
        vector<int>ans;
        
        for(auto i:mp){
            cout<<i.second.second<<"-";
            ans.push_back(i.second.second);
        }
        return ans;
        
    }
};

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Solution obj;
    vector<int>ans = obj.bottomView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
} 