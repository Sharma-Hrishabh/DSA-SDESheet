class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0){
                                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])] = nums[abs(nums[i])]*-1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};