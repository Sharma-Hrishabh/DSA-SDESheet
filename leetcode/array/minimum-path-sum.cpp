class Solution {
public:
    int solve(vector<vector<int>>& grid,int i, int j,int m, int n,vector<vector<int>>&dp){
        // at the end
        if(i==m-1 && j==n-1) return grid[i][j];
        // if the index is out of bounds return the max value to make it not considered
        if(i>=m || j>=n) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        int goDown = solve(grid,i+1,j,m,n,dp);
        int goRight = solve(grid,i,j+1,m,n,dp);
        dp[i][j] = grid[i][j]+min(goDown,goRight);
        
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(grid,0,0,m,n,dp);
        
        
    }
};