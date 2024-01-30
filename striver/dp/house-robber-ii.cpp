class Solution {
public:

    int solve(vector<int>&nums,vector<int>&dp,int start,int end){
        dp[start]=nums[start];
        for(int i=start+1;i<=end;i++){
            
            int pick = nums[i];
            if(start==0 && i>1) pick+=dp[i-2];
            else if(start==1 && i>2) pick+=dp[i-2]; 
            

            int dontpick = 0 +dp[i-1];

            dp[i]=max(pick,dontpick);

        }


        return dp[end];

    }
    int rob(vector<int>& nums) {
    
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1);

        int firstInclude = solve(nums,dp,0,n-2);

        for(int i=0;i<n;i++) dp[i]=-1;

        ///memset(dp,-1,sizeof(dp));

        int firstExclude = solve(nums,dp,1,n-1);

        return max(firstInclude,firstExclude);

    }
};