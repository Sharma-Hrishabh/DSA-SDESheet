//recursion

class Solution {
public:

    int solve(int i, int j){
        if(i==0 && j==0) return 1;
        else if(i<0) return 0;
        else if(j<0) return 0;

        return solve(i-1,j) + solve(i,j-1);

    }
 
    int uniquePaths(int m, int n) {

        return solve(m-1,n-1);
        
    }
};


//memoization

class Solution {
public:

    int solve(int i, int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        else if(i<0) return 0;
        else if(j<0) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j]=solve(i-1,j,dp) + solve(i,j-1,dp);
        return dp[i][j];

    }
 
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
        
    }
};

//dp
class Solution {
public:

    int solve(int m, int n,vector<vector<int>>&dp){

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                        dp[i][j]=1;
                        continue;
                    }
                    
                    int up=0;
                    int left = 0;
                    
                    if(i>0) 
                        up = dp[i-1][j];
                    if(j>0)
                        left = dp[i][j-1];
                        
                    dp[i][j] = up+left;
            }
        }

        return dp[m-1][n-1];
    }
 
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,dp);
        
    }
};