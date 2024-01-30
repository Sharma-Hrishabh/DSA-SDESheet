//top-bottom recursive

class Solution {
public:


    int solve(vector<vector<int>>& grid,int i, int j1, int j2, int m, int n){
        if(i<0) return -1e8;
        if(i==0 && j1==0 && j2==n-1) return grid[0][0]+grid[0][n-1];
        if(j1<0 || j1>=n || j2<0 || j2>=n ) return -1e8;

        int maxPoint = -1e8;

        for(int a = -1;a<2;a++){
            int x = i-1;
            int y1 = j1+a;
            for(int b=-1;b<2;b++){
                int y2 = j2+b;
                
                int point = solve(grid,x,y1,y2,m,n); 
                if(j1==j2) point+=grid[i][j1];
                else point += grid[i][j1]+grid[i][j2];
                maxPoint = max(maxPoint,point);
            }
        }

        return maxPoint;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = -1e8;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,solve(grid,m-1,i,j,m,n));
            }
        }
        return ans;
    }
};

//bottom-top recursive'

class Solution {
public:

      int solve(vector<vector<int>>& grid,int i, int j1, int j2, int m, int n){
        if(j1<0 || j1>=n || j2<0 || j2>=n ) return -1e8;

        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        } 

        int maxPoint = -1e9;

        for(int a = -1;a<2;a++){
            int x = i+1;
            int y1 = j1+a;
            for(int b=-1;b<2;b++){
                int y2 = j2+b;
                
                int point = solve(grid,x,y1,y2,m,n); 
                if(j1==j2) point+=grid[i][j1];
                else point += grid[i][j1]+grid[i][j2];
                maxPoint = max(maxPoint,point);
            }
        }

        return maxPoint;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid,0,0,n-1,m,n);
    }
};


//memoization

class Solution {
public:

      int solve(vector<vector<int>>& grid,int i, int j1, int j2, int m, int n,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n ) return -1e8;

        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        } 

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxPoint = INT_MIN;

        for(int a = -1;a<2;a++){
            int x = i+1;
            int y1 = j1+a;
            for(int b=-1;b<2;b++){
                int y2 = j2+b;
                
                int point = solve(grid,x,y1,y2,m,n,dp); 
                if(j1==j2) point+=grid[i][j1];
                else point += grid[i][j1]+grid[i][j2];
                maxPoint = max(maxPoint,point);
            }
        }

        return dp[i][j1][j2]=maxPoint;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n, -1)));
        return solve(grid,0,0,n-1,m,n,dp);
    }
};



// dp


class Solution {
public:

      int solve(vector<vector<int>>& grid,int m, int n,vector<vector<vector<int>>> &dp){


        for(int i=m-1;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    if(i==m-1){
                        if(j1==j2) dp[m-1][j1][j2]=grid[m-1][j1];
                        else dp[m-1][j1][j2] = grid[m-1][j1]+grid[m-1][j2];
                        continue;
                    } 

                int maxPoint = -1e8;
                for(int a = -1;a<2;a++){
                    for(int b=-1;b<2;b++){
                        int point=INT_MIN;
                        if(j1+a<0  || j2+b<0 || j1+a>=n || j2+b>=n){
                            // do nothing
                        }
                        else{
                            if(j1==j2) point=grid[i][j1];
                            else point = grid[i][j1]+grid[i][j2];
                            point += dp[i+1][j1+a][j2+b]; // solve(grid,x,y1,y2,m,n,dp); 
                        }
            
                        maxPoint = max(maxPoint,point);
                    }
                }
                dp[i][j1][j2]=maxPoint;
                }
            }
        }

        return dp[0][0][n-1];

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n, 0)));
        return solve(grid,m,n,dp);
    }
};