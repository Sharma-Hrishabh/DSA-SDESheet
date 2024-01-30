class Solution {
public:
    
    int solve(vector<int>& nums, int start, int end){
        //edge case when we reach the extreme element which will alwasys be peak
        if(start>=end) return start;
        
        int mid = start + (end-start)/2;
        
        // if right element is smaller then the peak will be in left
        if(nums[mid]>nums[mid+1]) return solve(nums,start,mid);
        else return solve(nums,mid+1,end);
        
        
    }
    
    int findPeakElement(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
        
    }
};