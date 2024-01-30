// keep searching in left for first occurrence of target & keep searching in right for last occurrence of target

class Solution {
public:
    
    int binarySearchFirst(vector<int>&nums,int target,int l,int r,int &first){
        if(l>r) return -1;
        
        int mid = l+(r-l)/2;
        
        if(nums[mid]>=target ){
            if(nums[mid]==target) first=mid;
            return binarySearchFirst(nums,target,l,mid-1,first);
        }
        else return binarySearchFirst(nums,target,mid+1,r,first);
        
    }
    
    int binarySearchLast(vector<int>& nums,int target,int l,int r,int &last){
        if(l>r) return -1;
        
        int mid = l+(r-l)/2;
        
        if(nums[mid]>target){
            return binarySearchLast(nums,target,l,mid-1,last);  
        }
        else {
            if(nums[mid]==target) last=mid;
            return binarySearchLast(nums,target,mid+1,r,last);
        }
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        //first occurence
        int first=-1;
        binarySearchFirst(nums,target,0,n-1,first);        
        //last occurence
        int last=-1;
        binarySearchLast(nums,target,0,n-1,last);
        
        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};