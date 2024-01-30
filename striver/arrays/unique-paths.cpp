// DP Solution

class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
        return dp[i][j];
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};


// O(N-1)
// O(1)
/*

m+n-2
    C
     n-1 or m-1

Out of the total m+n-2, if we fix the m-1 positions then we can get the ways


10C3 = 8*9*10
        /
        1*2*3
*/



class Solution {
public:
    
    int uniquePaths(int m, int n) {
    
        int N = m+n-2;
        int r = m-1;
        double ans=1;
        for(int i=1;i<=r;i++){
            ans = ans *  (N-r+i)/i;
        }
        return (int)ans;      
    }
};