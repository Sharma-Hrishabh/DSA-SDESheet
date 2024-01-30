//recursion
int solve(vector<int> &price, int idx, int N){
	if(idx==0){
		return N*price[0];
	}

	int notTake =  0 + solve(price,idx-1,N);
	int take = INT_MIN;
	if(idx+1<=N) take = price[idx] + solve(price,idx,N-idx-1);
	return max(notTake,take);

}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.

	return solve(price,n-1,n);

}


//memoization

int solve(vector<int> &price, int idx, int N,vector<vector<int>>&dp){
	if(idx==0){
		return N*price[0];
	}
	if(dp[idx][N]!=-1) return dp[idx][N];
	int notTake =  0 + solve(price,idx-1,N,dp);
	int take = INT_MIN;
	if(idx+1<=N) take = price[idx] + solve(price,idx,N-idx-1,dp);
	return dp[idx][N] = max(notTake,take);

}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return solve(price,n-1,n,dp);

}


//dp

int solve(vector<int> &price, int N,vector<vector<int>>&dp){

	for(int j=0;j<=N;j++){
		dp[0][j] = j*price[0];
	}

	for(int i=1;i<N;i++){
		for(int j=0;j<=N;j++){
			int notTake = dp[i-1][j];
			int take = INT_MIN;
			if(i+1<=j) take = price[i] + dp[i][j-i-1];
			dp[i][j]=max(notTake,take);
		}
	}

	return dp[N-1][N];

}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	return solve(price,n,dp);

}


//optimal

int solve(vector<int> &price, int N){

	vector<int>prev(N+1,0);
	vector<int>curr(N+1,0);

	for(int j=0;j<=N;j++){
		prev[j] = j*price[0];
	}

	for(int i=1;i<N;i++){
		for(int j=0;j<=N;j++){
			int notTake = prev[j];
			int take = INT_MIN;
			if(i+1<=j) take = price[i] + curr[j-i-1];
			curr[j]=max(notTake,take);
		}
		prev=curr;
	}

	return prev[N];

}

int cutRod(vector<int> &price, int n)
{
	return solve(price,n);

}
