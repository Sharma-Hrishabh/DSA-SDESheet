class Solution {
public:

    int binarySearch(vector<int>& nums,int low, int high){
        int mid = (low+high)/2;

        // base case
        if(low>=high) return low;

        if(mid%2==0){
            if(nums[mid]!=nums[mid+1] && mid+1<=high) return binarySearch(nums,low,mid);
            else return binarySearch(nums,mid+1,high);
        }
        else {
            if(nums[mid]!=nums[mid+1] && mid+1<=high) return binarySearch(nums,mid+1,high);
            else return binarySearch(nums,low,mid);
        }

        return low;
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        return nums[binarySearch(nums,0,nums.size()-1)];

    }
};