class Info{
public:
  int maxSum;
  int largest;
  int smallest;
  Info(int maxSum,int largest,int smallest){
      this->maxSum = maxSum;
      this->largest=largest;
      this->smallest=smallest;
  }
    
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info solve(TreeNode* root, int &ans){
        if(!root) return Info(0,INT_MIN,INT_MAX);
        
        Info left = solve(root->left,ans);
        Info right = solve(root->right,ans);
        
        //valid BST
        if(root->val>left.largest && root->val<right.smallest){

            //max will come from right, and min will come from left till this node
            ans = max(ans,root->val+left.maxSum+right.maxSum);
            return Info(root->val+left.maxSum+right.maxSum,max(root->val,right.largest),min(root->val,left.smallest));
        }
        ans = max(ans,max(left.maxSum,right.maxSum));
        return Info(max(left.maxSum,right.maxSum),INT_MAX,INT_MIN);
        
        
    }
    
    
    int maxSumBST(TreeNode *root)
    {
    	//Your code here
        int ans =0;
        
        Info t = solve(root,ans);
        if(ans<0) return 0;
    	return ans;
    }
};