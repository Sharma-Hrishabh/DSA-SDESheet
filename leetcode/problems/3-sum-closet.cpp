class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closetSum=0;
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){    
            int j = i+1;
            int k = n-1;
            while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            int diff = abs(target-sum);
            if(diff<ans){
                ans = diff;
                closetSum = sum;
                
            }
            //ans = min(diff,ans);   
            if(sum>target) k--;
            else j++;
            }
            
        }
        return closetSum;
    }
};