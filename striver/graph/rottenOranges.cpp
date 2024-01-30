class Solution {
public:


    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int m,int n){

        int ans=0;
        queue<pair<pair<int,int>,int>>q;


        // all 2 will start rotting other at same time so bfs is good
        // push all 2 at time 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j]=2;
                }
                
            }
        }

        while(!q.empty()){
            pair<int,int> node = q.front().first;
            int time = q.front().second;
            q.pop();
            int row = node.first;
            int col = node.second;

            if(time>ans) ans=time;

            // check 4 directions & rott them
            if(row>0 && grid[row-1][col]==1 && visited[row-1][col]!=2){
                grid[row-1][col]=2;
                visited[row-1][col]=2;
                q.push(make_pair(make_pair(row-1,col),time+1));
            }

            if(row<m-1 && grid[row+1][col]==1 && visited[row+1][col]!=2){
                grid[row+1][col]=2;
                visited[row+1][col]=2;
                q.push(make_pair(make_pair(row+1,col),time+1));
            }

            if(col>0 && grid[row][col-1]==1 && visited[row][col-1]!=2){
                grid[row][col-1]=2;
                visited[row][col-1]=2;
                q.push(make_pair(make_pair(row,col-1),time+1));
            }

            if(col<n-1 && grid[row][col+1]==1 && visited[row][col+1]!=2){
                grid[row][col+1]=2;
                visited[row][col+1]=2;
                q.push(make_pair(make_pair(row,col+1),time+1));
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;

    }


    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int m = grid.size(); //rows
        int n = grid[0].size(); //col

        vector<vector<int>>visited(m,vector<int>(n,0));
        
        return bfs(grid,visited,m,n);
        
    }
};