//recursion
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;


        int up = solve(grid,i-1,j);
        int left = solve(grid,i,j-1);

        return grid[i][j]+min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid,m-1,n-1);
    }
};


//memoization
class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(grid,i-1,j,dp);
        int left = solve(grid,i,j-1,dp);

        return dp[i][j]=grid[i][j]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};

//dp
class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n,vector<vector<int>>& dp){

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(up,left);

            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m,n,dp);
    }
};


//djikstra

class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(i<0 || i>=m) return false;
        if(j<0 || j>=n) return false;
        return true;
    }


    int solve(vector<vector<int>>& grid, int m, int n,vector<vector<int>>&distance){

        //priorityqueue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        distance[0][0]=grid[0][0];
        pq.push({distance[0][0],{0,0}});

        while(!pq.empty()){
            int weight = pq.top().first;
            pair<int,int> node = pq.top().second;
            int row=node.first;
            int col=node.second;
            pq.pop();
            

            //down
            int row1=node.first+1;
            int col1=node.second;
            if(isValid(row1,col1,m,n) && weight+grid[row1][col1] < distance[row1][col1]){
                distance[row1][col1]=weight+grid[row1][col1];
                pq.push({distance[row1][col1],{row1,col1}});
            }

            //right
            int row2=node.first;
            int col2=node.second+1;
            if(isValid(row2,col2,m,n) && weight+grid[row2][col2] < distance[row2][col2]){
                distance[row2][col2]=weight+grid[row2][col2];
                pq.push({distance[row2][col2],{row2,col2}});
            }

        }
        return distance[m-1][n-1];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,INT_MAX));
        return solve(grid,m,n,visited);
    }
};