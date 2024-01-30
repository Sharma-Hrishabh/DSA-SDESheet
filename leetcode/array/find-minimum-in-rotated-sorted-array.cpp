class Solution {
public:
    
    int solve(vector<int>& nums, int start, int end) {
        
        if(start>=end) return nums[start];
        
        int mid = start+(end-start)/2;
        //if the mid is greater than extreme right then min is in right
        if(nums[mid]>nums[end]) return solve(nums,mid+1,end);
        else return solve(nums,start,mid);
        
    }
    
    
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int res = solve(nums,0,n-1);
        
        return res;
    }
};