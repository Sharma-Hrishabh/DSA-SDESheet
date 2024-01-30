class Info{
public:
  int maxSize;
  int largest;
  int smallest;
  Info(int maxSize,int largest,int smallest){
      this->maxSize = maxSize;
      this->largest=largest;
      this->smallest=smallest;
  }
    
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info solve(Node* root){
        if(!root) return Info(0,INT_MIN,INT_MAX);
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        //valid BST
        if(root->data>left.largest && root->data<right.smallest){

            //max will come from right, and min will come from left till this node
            return Info(1+left.maxSize+right.maxSize,max(root->data,right.largest),min(root->data,left.smallest));
        }
        
        return Info(max(left.maxSize,right.maxSize),INT_MAX,INT_MIN);
        
        
    }
    
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root).maxSize;
    }
};