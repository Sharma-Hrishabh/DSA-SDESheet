#include<iostream>
#include<stack>
#include<vector>

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

bool isLeaf(Node* root){
    if(!root->left && !root->right) return true;
    return false;
}

void leftTraversal(Node* root,vector<int>&ans){
    if(!root) return;
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left) leftTraversal(root->left,ans);
    else leftTraversal(root->right,ans);

}

void leafNodeTraversal(Node* root,vector<int>&ans){
    if(!root) return;
    if(root->left) leafNodeTraversal(root->left,ans);
    if(isLeaf(root)) ans.push_back(root->data);
    if(root->right) leafNodeTraversal(root->right,ans);
}

void rightTraversal(Node* root,stack<int>&s){
    if(!root) return;
    if(root->right) rightTraversal(root->right,s);
    else rightTraversal(root->left,s);
    if(!isLeaf(root)) s.push(root->data);
}
vector<int> boundaryLevelOrderTraversal(Node* root){
    vector<int>ans;
    stack<int>s;
    // Left traversal w/o leaf nodes
    leftTraversal(root,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    // leaf node traversal
    leafNodeTraversal(root,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
        cout<<"\n";
    // right traversal w/o leaf nodes
    rightTraversal(root,s);
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    return ans;

}


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
    vector<int>ans = boundaryLevelOrderTraversal(root);
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }
    return 0;
} 