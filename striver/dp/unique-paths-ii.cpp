//recusrion
class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;

        return solve(i-1,j,obstacleGrid)+solve(i,j-1,obstacleGrid);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(m-1,n-1,obstacleGrid);

    }
};


//memoization
class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
       
        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j]=solve(i-1,j,obstacleGrid,dp)+solve(i,j-1,obstacleGrid,dp);
        return  dp[i][j];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(m-1,n-1,obstacleGrid,dp);

    }
};
//dp

class Solution {
public:
    int solve(int m, int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){

       // if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++){
                
                //base conditions
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                int up=0;
                int left = 0;
                
                if(i>0 && dp[i-1][j]!=-1) 
                    up = dp[i-1][j];
                if(j>0 && dp[i][j-1]!=-1)
                    left = dp[i][j-1];
                    
                dp[i][j] = up+left;
            }
        }
        
        return dp[m-1][n-1];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(m,n,obstacleGrid,dp);

    }
};