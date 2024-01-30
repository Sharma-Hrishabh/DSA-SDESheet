#include <bits/stdc++.h> 



//recursion

int minEnergy(int idx,vector<int>&heights){
    if(idx==0) return 0;

    int oneStep = minEnergy(idx-1,heights) + abs(heights[idx]-heights[idx-1]);
    int twoStep = INT_MAX;
    if(idx>1) twoStep = minEnergy(idx-2,heights) + abs(heights[idx]-heights[idx-2]);

    return min(oneStep,twoStep); 

}


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return minEnergy(n-1,heights);

}


//memoization
int minEnergy(int idx,vector<int>&heights,vector<int>&dp){
    if(idx==0) return 0;

    if(dp[idx]!=-1) return dp[idx];

    int oneStep = minEnergy(idx-1,heights,dp) + abs(heights[idx]-heights[idx-1]);
    int twoStep = INT_MAX;
    if(idx>1) twoStep = minEnergy(idx-2,heights,dp) + abs(heights[idx]-heights[idx-2]);

    dp[idx] = min(oneStep,twoStep); 
    return  dp[idx];

}


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    return minEnergy(n-1,heights,dp);

}


//space optimized

#include<bits/stdc++.h>
int minEnergy(int idx,vector<int>&heights){
    int prev1=0,prev2=0;
    int curr;
    for(int i=1;i<=idx;i++){
        int oneStep = prev1 + abs(heights[i]-heights[i-1]);
        int twoStep = INT_MAX;
        if(i>1) twoStep = prev2 + abs(heights[i]-heights[i-2]);
        curr = min(oneStep,twoStep);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;

}


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return minEnergy(n-1,heights);

}




//dp / bottom up

#include<bits/stdc++.h>
int minEnergy(int idx,vector<int>&heights,vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<=idx;i++){
        int oneStep = dp[i-1] + abs(heights[i]-heights[i-1]);
        int twoStep = INT_MAX;
        if(i>1) twoStep = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(oneStep,twoStep);
    }
    return dp[idx];

}


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    dp[0]=0;
    return minEnergy(n-1,heights,dp);

}
