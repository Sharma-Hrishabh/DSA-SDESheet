class Solution {
public:
    // O(N^2)
    void sortColors(vector<int>& nums) {
       // 0 R, 1 W, 2 B
        for(int i = 0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j]) swap(nums[i],nums[j]);
            }
        }
    }
};

class Solution {
public:
    // O(N)
    void sortColors(vector<int>& nums) {
       // 0 R, 1 W, 2 B
        int count0=0,count1=0,count2=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else count2++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(count0!=0) {
                nums[i]=0;
                count0--;
            }
            else if(count0==0 && count1!=0){
                nums[i]=1;
                count1--;
            }
            else {
                nums[i]=2;
                count2--;
            }
            
        }
    }
};

//Three Pointer

class Solution {
public:
    // O(N)
    void sortColors(vector<int>& nums) {
       // 0 R, 1 W, 2 B
       int low = 0, mid = 0, high = nums.size()-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

