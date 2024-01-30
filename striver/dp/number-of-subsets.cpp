#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,0));

        for(int i=0;i<n;i++) dp[i][0]=1;

        if(num[0]==0) dp[0][num[0]]=2;
        else if(num[0] <= tar) dp[0][num[0]]=1;

        /* 
        if(index==0) {
            if(tar==0 && nums[idx]==0) return 2;
            if(tar==0 || (tar==nums[0])) return 1

        }
        */

        
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){

                int dontPick = dp[i-1][j];

                int pick = 0;
                if(num[i]<=j) pick = dp[i-1][j-num[i]];

                dp[i][j]=pick+dontPick;

            }
        }

        return dp[n-1][tar];
}