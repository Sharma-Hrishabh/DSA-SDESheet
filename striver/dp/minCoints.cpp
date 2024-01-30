#include <bits/stdc++.h> 

int solve(int arr[], int idx, int amount){

    // if denomination array is not uniform
    if(idx==0){
        if(amount==0) return 0;

        if(amount%arr[0]==0){
            return amount/arr[0];
        }
        else return 1e8;
    }

    int dontPick = 0 + solve(arr,idx-1,amount);
    int pick =INT_MAX;
    if(arr[idx]<=amount){
        //dint reduce idx as supply is infinite
        pick = 1 + solve(arr,idx,amount-arr[idx]);
    }
    return min(dontPick,pick);

}

int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[9]={1,2,5,10,20,50,100,500,1000};

    return solve(arr,8,amount);

}



//memoization
#include <bits/stdc++.h> 

int solve(int arr[], int idx, int amount,vector<vector<int>>&dp){
    if(idx==0){
        if(amount==0) return 0;
        return amount/arr[0];
    }

    if(dp[idx][amount]!=-1) return dp[idx][amount];

    int dontPick = 0 + solve(arr,idx-1,amount,dp);
    int pick =INT_MAX;
    if(arr[idx]<=amount){
        pick = 1 + solve(arr,idx,amount-arr[idx],dp);
    }
    return dp[idx][amount] = min(dontPick,pick);

}

int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<vector<int>>dp(9,vector<int>(amount+1,-1));
    int arr[9]={1,2,5,10,20,50,100,500,1000};

    return solve(arr,8,amount,dp);

}

//space optimized
#include <bits/stdc++.h> 

int solve(int arr[], int n, int amount){

    vector<int>prev(amount+1,0);
    vector<int>curr(amount+1,0);


    for(int j=0;j<=amount;j++){
        if(j%arr[0]==0){
            prev[j]= j/arr[0];
        }
        else prev[j]= 1e8;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=amount;j++){
            int dontPick = 0 + prev[j];
            int pick = INT_MAX;
            if(arr[i]<=j){
                pick = 1 + curr[j-arr[i]];
            }
            curr[j] = min(dontPick,pick);
        }
        prev=curr;

    }

    return prev[amount];

}

int findMinimumCoins(int amount) 
{
    // Write your code here

    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int ans = solve(arr,9,amount);
    if(ans<1e8) return ans;

    return -1;

}
