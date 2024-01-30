class Solution {
public:
 

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        queue<int>q;
        vector<int>indegree(V,0);

        //reverse the graph
        vector<vector<int>> graphRev(V,vector<int>());
        for(int i=0;i<V;i++){
                for(auto itr:graph[i]){
                    graphRev[itr].push_back(i);
                    indegree[i]++;
                }
        }


        // initIndegree(graph,indegree,V);
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);
            for(auto itr:graphRev[node]){
                indegree[itr]--;
                if(indegree[itr]==0) q.push(itr);
            }

        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
        
    }
};



//djiikstra
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
