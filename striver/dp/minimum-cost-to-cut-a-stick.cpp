class Solution {
public:

    int solve(vector<int>& cuts, int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int cost = 1e8;
        for(int idx = i;idx<=j;idx++){
            int temp = cuts[j+1]-cuts[i-1] + solve(cuts,i,idx-1,dp) + solve(cuts,idx+1,j,dp);
            cost = min(cost,temp);
        }
        return dp[i][j]=cost;
    }

    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);


        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));

        return solve(cuts,1,c,dp);

    }
};