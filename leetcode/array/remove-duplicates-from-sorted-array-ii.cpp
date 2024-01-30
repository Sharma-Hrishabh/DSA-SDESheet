class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int temp=0;
        int last = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=last) {
                temp=0;last=nums[i];
            }            
            if(temp>=2) continue;
            nums[count++]=nums[i];
            temp++;
   
        }
        return count;
    }
};