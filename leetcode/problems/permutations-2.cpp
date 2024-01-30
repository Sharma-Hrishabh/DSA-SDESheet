s
class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int i,vector<int>&temp){
        // a,b,c
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        //fix letters in iterative manner and swap with the left-most position to keep it aside.
        for(int j=i;j<nums.size();j++){
            if(s.find(nums[j])!=s.end()) continue; 
            else s.insert(nums[j]);
            swap(nums[j],nums[i]);
            solve(nums,ans,i+1,temp);
            swap(nums[j],nums[i]);


        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,ans,0,temp);
        return ans;
    }
};