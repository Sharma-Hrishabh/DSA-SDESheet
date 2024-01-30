//recursion
class Solution {
public:

    int solve(vector<int>& prices, int idx, bool canBuy, int n){
        if(idx==n) return 0;

        if(canBuy){
            int buy = -prices[idx] + solve(prices,idx+1,false,n);
            int notBuy = solve(prices,idx+1,true,n);
            return max(buy,notBuy);
        }
        else{
            int sell = prices[idx] + solve(prices,idx+1,true,n);
            int notSell = solve(prices,idx+1,false,n);
            return max(sell,notSell); 
        }

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solve(prices,0,true,n);

    }
};


//memoization
class Solution {
public:

    int solve(vector<int>& prices, int idx, int canBuy, int n,vector<vector<int>>&dp){
        if(idx==n) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        if(canBuy){
            int buy = -prices[idx] + solve(prices,idx+1,0,n,dp);
            int notBuy = solve(prices,idx+1,1,n,dp);
            return dp[idx][canBuy] = max(buy,notBuy);
        }
        else{
            int sell = prices[idx] + solve(prices,idx+1,1,n,dp);
            int notSell = solve(prices,idx+1,0,n,dp);
            return dp[idx][canBuy] = max(sell,notSell); 
        }

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,true,n,dp);

    }
};


//dp

class Solution {
public:

    int solve(vector<int>& prices, int n,vector<vector<int>>&dp){
        
        dp[n][0]=0;
        dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            //can buy
            int buy = -prices[i] + dp[i+1][0]; 
            int notBuy = dp[i+1][1];
            dp[i][1] = max(buy,notBuy);

            //can't buy
            int sell = prices[i] + dp[i+1][1];
            int notSell = dp[i+1][0];;
            dp[i][0] = max(sell,notSell); 

        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,n,dp);

    }
};