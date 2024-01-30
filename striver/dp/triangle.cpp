//recursion
class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i, int j){
        if(i==0 && j==0) return triangle[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(j>=i+1) return INT_MAX;

        int up = solve(triangle,i-1,j);
        int diag = solve(triangle,i-1,j-1);

        return triangle[i][j] + min(up,diag);

    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int ans=INT_MAX;
        int m = triangle.size();
        int n = triangle[m-1].size();
        for(int i=0;i<n;i++){
            ans = min(ans,solve(triangle,m-1,i));
        }
        return ans;


    }
};

//memoization

class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i, int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return triangle[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(j>=i+1) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(triangle,i-1,j,dp);
        int diag = solve(triangle,i-1,j-1,dp);

        return dp[i][j]=triangle[i][j] + min(up,diag);

    }



    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        int m = triangle.size();
        int n = triangle[m-1].size();
        for(int i=0;i<n;i++){
            vector<vector<int>>dp(m,vector<int>(n,-1));
            ans = min(ans,solve(triangle,m-1,i,dp));
        }
        return ans;


    }
};


//dp
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(i<0 || j<0) return false;
        if(i>=m || j>=n) return false;
        if(j>=i+1) return false;
        return true;
    }

    int solve(vector<vector<int>>& triangle,int m, int n,vector<vector<int>>&dp){
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i==0 && j==0){
                    dp[0][0]=triangle[0][0];
                    continue;
                }
                if(!isValid(i,j,m,n)){
                    dp[i][j]=INT_MAX;
                    continue;
                }
                int up=INT_MAX,diag=INT_MAX;
                if(isValid(i-1,j,m,n)) up = dp[i-1][j];//solve(triangle,i-1,j,dp);
                if(isValid(i-1,j-1,m,n)) diag = dp[i-1][j-1];//solve(triangle,i-1,j-1,dp);
                dp[i][j]= triangle[i][j] + min(up,diag);

            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[m-1][i]);
        }

        return ans;
    }



    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(triangle,m,n,dp);


    }
};