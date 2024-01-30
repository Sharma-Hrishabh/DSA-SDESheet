class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int index,int n,int k){
        if(index==k) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1,n,k);
            temp.pop_back();
        }

        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()+1;i++){
            solve(nums,ans,{},0,nums.size(),i);
        }
        return ans;

    }
};