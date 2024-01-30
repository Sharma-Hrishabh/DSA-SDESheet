class Solution {
public:
   bool dfs(int start,vector<vector<int>>& graph, int color[],int currColor){
        color[start]=currColor;

        for(auto itr:graph[start]){
            if(color[itr]==-1){
                if(dfs(itr,graph,color,!currColor)==false) return false;
            }
            else if(color[itr]==currColor) return false;
        }
        return true;
    }
    
    bool bfs(int src,vector<vector<int>>& graph, int color[]){
        queue<int>q;
        
        q.push(src);
        color[src]=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto itr : graph[node]){
                if(color[itr]==-1){
                    //not colored
                    color[itr] = !color[node];
                    q.push(itr);
                }
                else if(color[itr]==color[node]) return false;
            }

        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        memset(color,-1,sizeof(color));

        for(int i=0;i<V;i++){
            if(color[i]==-1 && !bfs(i,graph,color)) return false;
        }
        return true;

    }
};