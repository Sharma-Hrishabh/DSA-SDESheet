class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>temp,int n,int k, int index){
        
        if(k==0){
            ans.push_back(temp);
           // if(temp.size()!=0) temp.pop_back();
            return;
        }
    
        if(index>n) return;
    
        
        //if(n-index-1<k) return;
        
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            solve(ans,temp,n,k-1,i+1);
            temp.pop_back();
        }
       // solve(ans,temp,n,k,index+1);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
  
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,n,k,1);
        return ans;
    
    }
};