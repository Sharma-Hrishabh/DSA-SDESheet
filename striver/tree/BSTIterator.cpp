class BSTIterator {
public:
    stack<TreeNode*>s;
      
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    void pushLeft(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    int next() {
        TreeNode* top = s.top();
        s.pop();
        pushLeft(top->right);

        return top->val;
    }
    
    bool hasNext() {
        if(s.size()==0) return false;
        return true;
    }
};
