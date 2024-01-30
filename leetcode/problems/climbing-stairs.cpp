class Solution {
public:
    
    void solve(int n,int sum,int& ans){
        if(sum==n) {
            ans++;
            return;
        }
        
        if(sum>n) return;
        
        solve(n,sum+1,ans);
        solve(n,sum+2,ans);
        
    }
    
    
    int climbStairs(int n) {
    
        int ans=0;
        solve(n,0,ans);
        return ans;        
    }
};



// DP
class Solution {
    int fn(int n, vector<int> &dp){
     if(n<0)return 0;
     if(n == 0)return 1;  
//    if the value of subproblem is already calulated then use it and do not solve it again.       
        if(dp[n] != -1)return dp[n];
//      here we are doing the memoization to store the value of current subproblem.
        dp[n] = fn(n-1, dp) + fn(n-2, dp);
        return dp[n];
    }
public:
  
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
      return fn(n, dp);
    }
};


// Tail Recurison
class Solution {
public:
    long climbStairs(int i, long a, long b, int n)
    {
        if (i == n)
            return a;
        else
            return climbStairs(i + 1, b, a + b, n);
    }
    long climbStairs(int n) {
        return climbStairs(1, 1, 2, n);
    }
};
