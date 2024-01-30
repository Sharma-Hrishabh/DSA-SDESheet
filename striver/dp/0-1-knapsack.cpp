//recusrion
#include <bits/stdc++.h> 
int solve(int weights[], int values[], int idx, int w){
	if(idx==0){
		if(weights[0]<=w) return values[0];
		else return 0;
	}

	if(w==0) return 0;
	
	int dontPick = solve(weights,values,idx-1,w);
	int pick = INT_MIN;
	if(weights[idx]<=w) pick = solve(weights,values,idx-1,w-weights[idx]) + values[idx];

	return max(pick,dontPick);

}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	return solve(weights,values,n-1,maxWeight);

}

//memoization
#include <bits/stdc++.h> 
int solve(int weights[], int values[], int idx, int w,vector<vector<int>>&dp){
	if(idx==0){
		if(weights[0]<=w) return values[0];
		else return 0;
	}

	if(w==0) return 0;

	if(dp[idx][w]!=-1) return dp[idx][w];
	
	int dontPick = solve(weights,values,idx-1,w,dp);
	int pick = INT_MIN;
	if(weights[idx]<=w) pick = solve(weights,values,idx-1,w-weights[idx],dp) + values[idx];

	return dp[idx][w]=max(pick,dontPick);

}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solve(weights,values,n-1,maxWeight,dp);

}


//also
    int solve(int idx, int W, int wt[], int val[],vector<vector<int>>&dp){
        if(idx<0) return 0;
        // if(idx==0) {
        //     if(wt[0] <=W) return val[0];
        //     else return 0;        
        // }


        if(dp[idx+1][W]!=-1) return dp[idx+1][W];
        
        int notTake = solve(idx-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[idx]<=W) take = solve(idx-1,W-wt[idx],wt,val,dp) + val[idx];
        
        return dp[idx+1][W] = max(notTake,take);
        
    }



//dp

#include <bits/stdc++.h> 
int solve(int weights[], int values[], int n, int w,vector<vector<int>>&dp){
	
	// for any weight at index 0 greater eq than weight of 0th index
	for(int W=weights[0];W<=w;W++){
		dp[0][W] = values[0];
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<=w;j++){
			int dontPick = dp[i-1][j];
			int pick = INT_MIN;
			if(weights[i]<=j) pick = dp[i-1][j-weights[i]] + values[i];
			dp[i][j] = max(dontPick,pick);

		}
	}

	return dp[n-1][w];

}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	return solve(weights,values,n,maxWeight,dp);

}


//also

 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       //for idx == 0
       
       
    //   for(int i=wt[0];i<=W;i++){
    //         dp[0][i]=val[0];
    //   }
       
       
       for(int idx = 0; idx<n; idx++){
           for(int w = 0;w<=W;w++){
               
            int notTake = dp[idx][w];//solve(idx-1,W,wt,val,dp);
            int take=INT_MIN;
            if(wt[idx]<=w) take = val[idx] + dp[idx][w-wt[idx]];//solve(idx-1,W-wt[idx],wt,val,dp) + 
            
            dp[idx+1][w] = max(notTake,take);
                   
           }
       }
       
       return dp[n][W];
       
    }
	