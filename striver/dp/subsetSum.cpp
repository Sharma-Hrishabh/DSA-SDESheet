//recursion
//o(2^N)
//o(N) for recursion stack
#include <bits/stdc++.h>
bool solve(int idx, int k, vector<int>& arr){
    if(k==0) return true;

   // if(idx==0 && arr[0]==k) return true; 
    if(k<0 || idx<0) return false;

    bool pick = solve(idx-1,k-arr[idx],arr);
    bool dontPick = solve(idx-1,k,arr);

    return pick || dontPick;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n-1,k,arr);
}

//memoixation
//O(N*K)
// S(N*K) + S(n) for recursion stack
#include <bits/stdc++.h>
bool solve(int idx, int k, vector<int>& arr,vector<vector<int>>dp){
    if(k==0) return true;

    //if(idx==0) return (arr[0]==k); 
    if(k<0 || idx<0) return false;

    if(dp[idx][k]!=-1) return dp[idx][k];



    bool dontPick = solve(idx-1,k,arr,dp);

    //bool pick = false;
    //if(k>=arr[idx]) pick = solve(idx-1,k-arr[idx],arr,dp);
    bool pick = solve(idx-1,k-arr[idx],arr,dp);
    
    return dp[idx][k] = (pick || dontPick);

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}



//dp

#include <bits/stdc++.h>
bool solve(int idx, int k, vector<int>& arr,vector<vector<bool>>&dp){

    for(int i=0;i<=idx;i++){
        for(int j=0;j<=k+1;j++){
            if (j == 0) {
                dp[i][0] = true;
                continue;
          }
          //no matter what target is if its equals to a[0] then true, if it is less than target
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

    return dp[idx][k];


}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    return solve(n-1,k,arr,dp);
}