//memoization
class Solution {
public:

    int solve(vector<int>& prices, int idx, int canBuy, int tx, int n,vector<vector<vector<int> > > &dp){
        if(tx==0) return 0;
        if(idx==n) return 0;

        if(dp[idx][canBuy][tx] != -1) return dp[idx][canBuy][tx];

        if(canBuy){
            int buy = -prices[idx] + solve(prices,idx+1,0,tx,n,dp);
            int notBuy = solve(prices,idx+1,1,tx,n,dp);
            return dp[idx][canBuy][tx] = max(buy,notBuy);
        }
        else{
            int sell = prices[idx] + solve(prices,idx+1,1,tx-1,n,dp);
            int notSell = solve(prices,idx+1,0,tx,n,dp);
            return dp[idx][canBuy][tx] = max(sell,notSell); 
        }

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
          vector<vector<vector<int> > > dp(
        n, vector<vector<int> >(2, vector<int>(3, -1)));
        return solve(prices,0,1,2,n,dp);

    }
};


//dp
class Solution {
public:

    int solve(vector<int>& prices, int n,vector<vector<vector<int> > > &dp){
        for(int i=n-1;i>=0;i--){
            for(int tx=1;tx<=2;tx++){
                //buy
                int buy = -prices[i] +  dp[i+1][0][tx];
                int notBuy = dp[i+1][1][tx];
                dp[i][1][tx] = max(buy,notBuy);

                //donty buy

                int sell = prices[i] + dp[i+1][1][tx-1];
                int notSell = dp[i+1][0][tx];
                dp[i][0][tx] = max(sell,notSell); 

            }
        }
        return dp[0][1][2];

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
          vector<vector<vector<int> > > dp(
        n+1, vector<vector<int> >(2, vector<int>(3, 0)));
        return solve(prices,n,dp);

    }
};