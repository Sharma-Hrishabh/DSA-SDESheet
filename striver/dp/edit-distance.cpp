class Solution {
public:
    int solve(int i, int j, string s1, string s2,vector<vector<int>>&dp){

        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];

        if(s1[i]==s2[j]) return dp[i+1][j+1] = solve(i-1,j-1,s1,s2,dp);
        else{
            int ins = 1+solve(i,j-1,s1,s2,dp);
            int del = 1+solve(i-1,j,s1,s2,dp);
            int rep = 1+solve(i-1,j-1,s1,s2,dp);
            return dp[i+1][j+1] = min(ins,min(del,rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n-1,m-1,word1,word2,dp);

    }
};


// 1- based indexing
class Solution {
public:
    int solve(int i, int j, string s1, string s2,vector<vector<int>>&dp){

        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else{
            int ins = 1+solve(i,j-1,s1,s2,dp);
            int del = 1+solve(i-1,j,s1,s2,dp);
            int rep = 1+solve(i-1,j-1,s1,s2,dp);
            return dp[i][j] = min(ins,min(del,rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n,m,word1,word2,dp);

    }
};
// dp
class Solution {
public:

    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])  dp[i][j] = dp[i-1][j-1];//solve(i-1,j-1,s1,s2,dp);
                else{
                    int ins = 1+dp[i][j-1];//solve(i,j-1,s1,s2,dp);
                    int del = 1+dp[i-1][j];//solve(i-1,j,s1,s2,dp);
                    int rep = 1+dp[i-1][j-1];//solve(i-1,j-1,s1,s2,dp);
                    dp[i][j] = min(ins,min(del,rep));
                }

            }
        }

        return dp[n][m];

    }
};



class Solution {
public:

 int minDistance(string S1, string S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                cur[j] = 0+prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev = cur;
    }
    
    return prev[m];
    
}
};