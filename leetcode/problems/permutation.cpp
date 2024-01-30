// O(N!*n)
// O(1)/O(1))


//FOR MARKING WE CAN ALSO MARK ELEMENT IN an unordered map that they have been picked rather than moving them to left but it will increase space complexity
class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int i,vector<int>&temp){
        // a,b,c
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //fix letters in iterative manner and swap with the left-most position to keep it aside.
        for(int j=i;j<nums.size();j++){
        
            swap(nums[j],nums[i]); 
            solve(nums,ans,i+1,temp);
            swap(nums[j],nums[i]);


        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,ans,0,temp);
        return ans;
    }
};