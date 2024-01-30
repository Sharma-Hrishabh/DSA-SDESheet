class Solution {
public:

    bool detectCycle(int n, vector<int>adj[],int visited[],int src){

        queue<pair<int,int>>q;
        visited[src]=1;
        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neighbor:adj[node]){
                if(!visited[neighbor]){
                    //visit
                    visited[neighbor]=1;
                    q.push({neighbor,node});
                }
                else if(parent!=neighbor){
                    // if it is already visited and it is not the parent of the current node, means there is a cycle
                    return true;
                }
            }
        }
        return false;

    }

    void addEdge(vector<int>adj[], int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclic(int n, vector<int>adj[],int visited[]){
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectCycle(n,adj,visited,i)==true) return true;
            }
        }
        return false;
    }

};