class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=m) return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

      
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            
            dis[i][j]=d;

            q.pop();

            int dR[4] = {0,-1,0,1};
            int dC[4] = {-1,0,1,0};

            for(int x=0;x<4;x++){
                int row = i + dR[x];
                int col = j + dC[x];

                if(isValid(row,col,m,n) && vis[row][col]==0){
                        q.push({{row,col},d+1});
                        vis[row][col]=1;
                }

            }
        }

        return dis;

        
    }
};