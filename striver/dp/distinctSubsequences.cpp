//exponential
class Solution {
public:
    int solve(string s, string t, int i, int j){
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i]==t[j]) return solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
        return solve(s,t,i-1,j);
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return 0;
        return solve(s,t,n-1,m-1);
    }
};

//memoization

class Solution {
public:
    int solve(string s, string t, int i, int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        return dp[i][j] = solve(s,t,i-1,j,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};



//dp
class Solution {
public:
    int solve(string s, string t, int n, int m,vector<vector<double>>&dp){

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return 0;
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        return solve(s,t,n,m,dp);
    }
};




//space optimzied
class Solution {
public:
    int solve(string s, string t, int n, int m){

        vector<double>prev(m+1,0);
        vector<double>curr(m+1,0);
            prev[0]=1;
            curr[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1] + prev[j];
                else curr[j] = prev[j];
            }
            prev=curr;
        }

        return (int)prev[m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return 0;
        return solve(s,t,n,m);
    }
};


//1-D

class Solution {
public:
    int solve(string s, string t, int n, int m){

        vector<double>prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) prev[j] = prev[j-1] + prev[j];
            }
        }
        return (int)prev[m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return 0;
        return solve(s,t,n,m);
    }
};