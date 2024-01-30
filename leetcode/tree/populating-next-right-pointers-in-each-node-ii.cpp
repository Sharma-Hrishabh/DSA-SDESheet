class Solution {
public:
     Node* findNext(const Node* node) {
        /* Find the next node in sublevel; returns the first child
           of left to right, if no children in node, recurse
           to find the first child in next node */
        if (!node) return nullptr;
        if (node->left ) return node->left;
        if (node->right) return node->right;
        return findNext(node->next);
    }
    
    Node* connect(Node* root) {
        if (!root) return root;
        // if has left child, connect to right
        // if right not exist, connect to findNext
        // if has right child, connect to findNext
        if (root->left)
            root->left->next = root->right ? root->right : findNext(root->next);
        if (root->right)
            root->right->next = findNext(root->next);
        // IMPORTANT: Traverse (dfs) the right subtree first, so while 
        // populating left subtree all the values in right are placed
        connect(root->right);
        connect(root->left);
        return root;    
    }
};