class Solution {
public:
    
    int binarySearch(vector<int>&nums,int l,int r,int target){
        if(l>r) return -1;

        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) return binarySearch(nums,l,mid-1,target);
        else return binarySearch(nums,mid+1,r,target);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //find pivot
        int pivot=-1;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) {
                pivot=i+1;
                break;
            }
        }
        
        if(pivot==-1) return binarySearch(nums,0,n-1,target);
        if(nums[pivot]==target) return pivot;
        // if they value is greather than the extreme right element then search in left half of pivot
        if(target>nums[n-1]) return binarySearch(nums,0,pivot-1,target);
        else return binarySearch(nums,pivot+1,n-1,target);
        
    }
};