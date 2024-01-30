//iterative

class Solution {
public:

    bool solve(int n, int k, vector<int>& arr,vector<vector<bool>>&dp){

        vector<bool>prev(k+1,false);
        vector<bool>curr(k+1,false);

        prev[0] = true;
        curr[0] = true;
        
        if(arr[0]<=k) curr[arr[0]]=true;

        for(int i=0;i<n;i++){
            for(int j=0;j<=k+1;j++){

                bool dontPick = prev[j];
                bool pick=false;
                if(j>=arr[i]) pick = prev[j-arr[i]];
                curr[j] = pick || dontPick;
            }
            prev=curr;
        }

        return prev[k];


    }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    return solve(n,k,arr,dp);
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(nums.size()<2) return false;
        if(sum%2!=0) return false;
        else return subsetSumToK(nums.size(),sum/2,nums);

    }
};

//correct dp

class Solution {
public:

    bool solve(int n, int k, vector<int>& arr,vector<vector<bool>>&dp){

        for(int i=0;i<n;i++){
            for(int j=0;j<=k+1;j++){
            if (j == 0) {
                dp[i][0] = true;
                continue;
            }
            //no matter what target is if its equals to a[0] then true
                if (i == 0 )
                {
                    if(arr[0]<=k) dp[i][arr[0]] = true;
                    continue;
                }
                bool dontPick = dp[i-1][j];
                bool pick=false;
                if(j>=arr[i]) pick = dp[i-1][j-arr[i]];


                dp[i][j] = pick || dontPick;

            }
        }

        return dp[n-1][k];


    }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    return solve(n,k,arr,dp);
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(nums.size()<2) return false;
        if(sum%2!=0) return false;
        else return subsetSumToK(nums.size(),sum/2,nums);

    }
};



//recusrion
class Solution {
public:

    bool solve(vector<int>& nums, int idx, int sum1, int sum2){
        if(idx == 0) return (abs(sum1-sum2)==nums[0]);

        bool includeInOne = solve(nums,idx-1,sum1+nums[idx],sum2);

        bool includeInTwo = solve(nums,idx-1,sum1,sum2+nums[idx]);

        return (includeInOne || includeInTwo);

    }

    bool canPartition(vector<int>& nums) {
        return solve(nums,nums.size()-1, 0, 0);

    }
};


// memoization

class Solution {
public:

    bool solve(vector<int>& nums, int idx, int sum1, int sum2,vector<vector<vector<int>>>&dp){
        if(idx == 0) return (abs(sum1-sum2)==nums[0]);

        if(dp[idx][sum1][sum2]!=-1) return dp[idx][sum1][sum2];

        bool includeInOne = solve(nums,idx-1,sum1+nums[idx],sum2,dp);

        bool includeInTwo = solve(nums,idx-1,sum1,sum2+nums[idx],dp);

        return dp[idx][sum1][sum2] = (includeInOne || includeInTwo);

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];

        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(sum+1,vector<int>(sum+1,-1)));
        return solve(nums,nums.size()-1, 0, 0,dp);

    }
};