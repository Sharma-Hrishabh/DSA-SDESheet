#include <bits/stdc++.h> 

//recursive
int solve(vector<int>&nums, int idx){
    if(idx==0) return nums[0];
    if(idx<0) return 0;

    //pick
    int pick = nums[idx]+solve(nums,idx-2);
    int dontpick = 0 +solve(nums,idx-1);

    return max(pick,dontpick);

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
   // vector<int>dp(nums.size(),-1);

    return solve(nums,nums.size()-1);
}

//memoization
#include <bits/stdc++.h> 

int solve(vector<int>&nums, int idx,vector<int>&dp){
    if(idx==0) return nums[0];
    if(idx<0) return 0;

    if(dp[idx]!=-1) return dp[idx];
    //pick
    int pick = nums[idx]+solve(nums,idx-2,dp);
    int dontpick = 0 +solve(nums,idx-1,dp);

    dp[idx]=max(pick,dontpick);

    return dp[idx];

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
   vector<int>dp(nums.size(),-1);

    return solve(nums,nums.size()-1,dp);
}

//dp

#include <bits/stdc++.h> 

int solve(vector<int>&nums,vector<int>&dp){
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        
        int pick = nums[i]+ ((i>1)?dp[i-2]:0);
        

        int dontpick = 0 +dp[i-1];

        dp[i]=max(pick,dontpick);

    }
    return dp[nums.size()-1];

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size(),-1);
    return solve(nums,dp);
}


