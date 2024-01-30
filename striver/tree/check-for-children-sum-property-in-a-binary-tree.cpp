#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

// O(N)
void reorder(node* root){
    if(!root) return;

    int childSum = 0;

    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum>=root->data){
        root->data = childSum;
    }
    else{
        if(root->left)  root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    reorder(root->left);
    reorder(root->right);

    childSum=0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(root->left || root->right){
        root->data=childSum;
    }
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);

  return 0;
}