class Solution {
public:

    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int n, int m,int u, int v){
        visited[u][v]=1;

            // check up
            if(u-1>=0 && !visited[u-1][v] && grid[u-1][v]=='1') {
                dfs(grid,visited,n,m,u-1,v);
            }
            // check down
            if(u+1<n && !visited[u+1][v] && grid[u+1][v]=='1') {
                dfs(grid,visited,n,m,u+1,v);
            }

            //check left
            if(v-1>=0 && !visited[u][v-1] && grid[u][v-1]=='1') {
                dfs(grid,visited,n,m,u,v-1);
            }f

            //check right
            if(v+1<m && !visited[u][v+1] && grid[u][v+1]=='1') {
                dfs(grid,visited,n,m,u,v+1);
            }
    }
    
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int n, int m,int i, int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;

        while(!q.empty()){
            pair<int,int>node = q.front();
            q.pop();
            int u = node.first;
            int v = node.second;
            visited[u][v]=1;

            // check up
            if(u-1>=0 && !visited[u-1][v] && grid[u-1][v]=='1') {
                q.push({u-1,v});
                visited[u-1][v]=1;
            }
            // check down
            if(u+1<n && !visited[u+1][v] && grid[u+1][v]=='1') {
                q.push({u+1,v});
                visited[u+1][v]=1;
            }

            //check left
            if(v-1>=0 && !visited[u][v-1] && grid[u][v-1]=='1') {
                q.push({u,v-1});
                visited[u][v-1]=1;
            }

            //check right
            if(v+1<m && !visited[u][v+1] && grid[u][v+1]=='1') {
                q.push({u,v+1});
                visited[u][v+1]=1;
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) visited[i][j]=0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(grid,visited,n,m,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

};