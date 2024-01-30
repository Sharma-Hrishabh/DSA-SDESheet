//memoization
// O(N*Amount)
// O(N*AMOUNT) + O(AMOUNT)


class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(amount==0) return 0;

        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return INT_MAX-1;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int notTake = solve(i-1,amount, coins,dp);
        int take=INT_MAX-1;
        if(coins[i]<=amount) take = 1+solve(i,amount-coins[i],coins,dp);
        return dp[i][amount] =  min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       // if(amount==0) return 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        return ans==INT_MAX-1?-1:ans;

    }
};




//dp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));

        for(int i=0;i<n;i++) dp[i][0]=0;

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            //else already 1e9
        }

        for(int i=1;i<n;i++){
            for(int t=1;t<=amount;t++){
                int notTake = dp[i-1][t];
                int take = INT_MAX;
                if(coins[i]<=t) take = 1+dp[i][t-coins[i]];
                dp[i][t] = min(take,notTake);
            }
        }

        int ans = dp[n-1][amount];
        return ans==1e9?-1:ans;

    }
};


#include <iostream>
#include<vector>
#include<map>
using namespace std; 
int solve(int amount, vector<int>&a,map<int,int>&dp){
    for(int k=1;k<=amount;k++){
        int minAns = INT_MAX;
        for(int i=0;i<a.size();i++){
            if (k >= a[i]) {
                int coins = k/a[i];
                int remainAmount = k%a[i];
                if(dp.find(remainAmount)==dp.end()){
                    dp[remainAmount] = solve(remainAmount,a,dp);
                } 
                minAns = min(coins+dp[remainAmount],minAns);
                 
                dp[k] = minAns;
            }        
        }
    }
    return dp[amount];
}

int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>a;
    // = {1,2,5,10,20,50,100,500,1000};
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    a.push_back(10);
    a.push_back(20);
    a.push_back(50);
    a.push_back(100);
    a.push_back(500);
    a.push_back(1000);

    map<int,int>dp;
    dp[0]=0;
    int x = solve(amount,a,dp);
    // for(auto itr = dp.begin();itr!=dp.end();itr++){
    //     cout<<itr->first<<" "<<itr->second<<endl;
    // }
     return x;

}

int main(){
    int amount=96;
    // cin>>amount;
    cout<<findMinimumCoins(amount);
    return 0;
}