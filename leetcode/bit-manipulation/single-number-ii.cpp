class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;
        
        // Iterate through all the bits one by one for all the elments of array.
        for(int i=0;i<32;i++){
            
            int mask = 1<<i;
            int count=0;
            for(int j=nums.size()-1;j>=0;j--){
                // check for how many array element that bit is set
                if(mask&nums[j]) count++;
            }
            
            // if the no of times bit is set in the array is not multiple of three them it has appeared once, and is part of forming a number which has appeared once only. 
            // so take an OR with ans to form that element.
            if(count%3!=0) ans|=mask;
        }
        
        return ans;
    }
};