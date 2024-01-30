class Solution {
  public:
  
    void dfs(vector<int>adj[], int visited[], int start,vector<int>&ans){
        
        visited[start]=1;
        ans.push_back(start);
        
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(adj,visited,it,ans);
            }
        }
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        vector<int>ans;
        int start=0;
        
        dfs(adj,visited,start,ans);
        
        return ans;
        
    }
};