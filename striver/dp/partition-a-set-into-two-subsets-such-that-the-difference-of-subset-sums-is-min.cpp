#include <bits/stdc++.h> 


int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0;i<n;i++) sum+=arr[i];

	int k =sum;

	vector<vector<bool>>dp(n,vector<bool>(k+1,false));
	// if target is 0 at any index
	for(int i=0;i<n;i++) dp[i][0]=true;

	//if at index=0 and target equals to that element
	if(arr[0]<=k) dp[0][arr[0]]=true;

	for(int i=1;i<n;i++){
		for(int j=1;j<k+1;j++){
			bool dontPick = dp[i-1][j];
			bool pick=false;
			if(arr[i]<=j) pick = dp[i-1][j-arr[i]];

			dp[i][j] = pick || dontPick;
		}
	}

	// possible sums from last index is in last row of DP

	int ans = INT_MAX;

	for(int i=k;i>=0;i--){
		if(dp[n-1][i]) ans=min(ans,abs(2*i- k));
	}

	return ans;

}
