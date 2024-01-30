class Solution{
    {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isValid(int i, int j, int m, int n){
        if(i<0) return false;
        if(i>=m) return false;
        if(j<0) return false;
        if(j>=n) return false;
        return true;
    }
	void bfs(vector<vector<int> >&grid,vector<vector<int>>&vis,vector<vector<int>>&dis,int m, int n){
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        pair<int,int>cord = q.front().first;
	        int d = q.front().second;
	        int row = cord.first;
	        int col = cord.second;
	        dis[row][col]=d;
	        q.pop();
	        int dR[4] = {0,1,0,-1};
	        int dC[4] = {-1,0,1,0};
	        
	        for(int i=0;i<4;i++){
	            int nR = row+dR[i];
	            int nC = col+dC[i];
	            if(isValid(nR,nC,m,n) && !vis[nR][nC]){
	                q.push({{nR,nC},d+1});
	                vis[nR][nC]=1;
	            }
	            
	        }
	        
	    }
	    
	    
	    
	}
    // the idea is to propgate 1's from all the 1's in the grid and keep track of the distance from the nearest 1
	vector<vector<int>>nearest(vector<vector<int> >grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int> > vis(m,vector<int>(n,0));
	    vector<vector<int> > dis(m,vector<int>(n,0));

        bfs(grid,vis,dis,m,n);
	    
	    return dis;
	    
	}
};