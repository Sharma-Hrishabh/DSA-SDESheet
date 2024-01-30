


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1 3 5 4 2
        // Find a breakpoint from right to left where a[i] < a[i+1]. we will get a prefix which we need 
        // to increase to the next greater permutation, and all the elements to the right will already bein decreaing order, so cant be touched.
        int n = nums.size();
        int breakPoint;
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<nums[i+1]){
                breakPoint = i; 
                break;
            }
        }
        
        // If no breakpoint is found, it means the array is in decreasing order, so reverse it and return
        if(breakPoint<0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        // Find the next greater element to the breakpoint element from right so that we can swap and place it in the breakpoint position to increase prefix.
        // 1 4 5 3 2  - this is not the next permutation, so reverse the sequence after the breakpoint to get the next permutation.
        int k;
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[breakPoint]){
              k = j;
                break;
            }
        }
        swap(nums[breakPoint],nums[k]);
        
        reverse(nums.begin()+breakPoint+1,nums.end());
        
        
        
    }
};