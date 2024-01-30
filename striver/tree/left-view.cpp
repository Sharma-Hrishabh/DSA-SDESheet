
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(!root) return ans;
   queue<Node*>q;
   q.push(root);

   while(!q.empty()){
        int n =q.size();
        
        for(int i=1;i<=n;i++){
            Node* f = q.front();
            q.pop();
            if(i==1) ans.push_back(f->data);
            if(f->left) q.push(f->left);   
            if(f->right) q.push(f->right);
        }

      
   }
   return ans;
}
