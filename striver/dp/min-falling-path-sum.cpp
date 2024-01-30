class Solution {
public:

    int solve(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(j>n-1 || j<0) return INT_MAX;
        if(i==0) return matrix[0][j];

        int up = solve(matrix,i-1,j,m,n);
        int diagLeft = solve(matrix,i-1,j-1,m,n);
        int diagRight = solve(matrix,i-1,j+1,m,n);

        return matrix[i][j]+min(up,min(diagLeft,diagRight));        

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,solve(matrix,m-1,i,m,n));
        }
        return ans;
    }
};


//memoization

class Solution {
public:

    int solve(vector<vector<int>>& matrix, int i, int j, int m, int n,vector<vector<int>>&dp){
        if(j>n-1 || j<0) return INT_MAX;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(matrix,i-1,j,m,n,dp);
        int diagLeft = solve(matrix,i-1,j-1,m,n,dp);
        int diagRight = solve(matrix,i-1,j+1,m,n,dp);

        return dp[i][j]=matrix[i][j]+min(up,min(diagLeft,diagRight));        

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            ans = min(ans,solve(matrix,m-1,i,m,n,dp));
        }
        return ans;
    }
};


//dp
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(j>n-1 || j<0) return false;
        if(i>m-1 || i<0) return false;
        return true;
    }

    int solve(vector<vector<int>>& matrix,int m, int n,vector<vector<int>>&dp){


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                    continue;
                }

                int up=INT_MAX,diagLeft=INT_MAX,diagRight=INT_MAX;

                if(isValid(i-1,j,m,n)) up = dp[i-1][j];//solve(matrix,i-1,j,m,n,dp);
                if(isValid(i-1,j-1,m,n)) diagLeft = dp[i-1][j-1];//solve(matrix,i-1,j-1,m,n,dp);
                if(isValid(i-1,j+1,m,n)) diagRight = dp[i-1][j+1];//solve(matrix,i-1,j+1,m,n,dp);

                dp[i][j]=matrix[i][j]+min(up,min(diagLeft,diagRight));
            }
        }


        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }

        return ans;

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(matrix,m,n,dp);
    }
};