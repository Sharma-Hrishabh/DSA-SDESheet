class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>efforts(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;

        efforts[0][0]=0;
        q.push({0,{0,0}});

        int dR[4] = {-1,0,1,0};
        int dC[4] = {0,1,0,-1};   
        
        while(!q.empty()){
            int dis = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            // if dest is reached for future, dis can be greater as it is being maximised so we can return it
            if (row == m - 1 && col == n - 1) return dis;

            //relax all directions 
            for(int i=0;i<4;i++){

                    int newRow = row+dR[i];
                    int newCol = col+dC[i];
                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n)
                    {
                        int newDis = max(dis,abs(heights[newRow][newCol]-heights[row][col]));
                        if(newDis<efforts[newRow][newCol]){
                            efforts[newRow][newCol] = newDis;
                            q.push(make_pair(newDis,make_pair(newRow,newCol)));
                        }
                    }   
            }
        }
        //not reachable
        return 0;
    }
};

