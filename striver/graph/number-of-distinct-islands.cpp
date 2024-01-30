  public:
      bool isValid(int i, int j, int m, int n){
        if(i<0) return false;
        if(i>=m) return false;
        if(j<0) return false;
        if(j>=n) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i, int j, int m, int n,vector<pair<int,int>>&island,int row0, int col0){
        vis[i][j]=1;
        
        int dR[4] = {0,1,0,-1};
        int dC[4] = {-1,0,1,0};
        
        for(int it=0;it<4;it++){
            int newRow = i + dR[it];
            int newCol = j + dC[it];
            
            if(isValid(newRow,newCol,m,n) && !vis[newRow][newCol] && grid[newRow][newCol]==1){
                int u = newRow-row0;
                int v = newCol-col0;
                island.push_back(make_pair(u,v));    
                dfs(grid,vis,newRow,newCol,m,n,island,row0,col0);
            }
            
        }
        
    }
  
    // just store the shapes in a set
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) {
                    vector<pair<int,int>>island;
                    dfs(grid,vis,i,j,m,n,island,i,j);
                    s.insert(island);
                }
            }
        }
        return s.size();
        
    }