class Solution {
public:

    bool detectCycle( vector<int>adj[],int visited[],int node,int parent){

        visited[node]=1;

        for(auto it:adj[node]){
            if(!visited[it]){
                if(detectCycle(adj,visited,it,node)==true) return true;
            }
            else if(it!=parent) return true;
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