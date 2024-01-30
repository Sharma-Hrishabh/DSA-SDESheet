class Solution {
  public:
  
    void dfs(vector<int>adj[], int visited[], int start,stack<int>&s){
        
        visited[start]=1;
        
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(adj,visited,it,ans);
            }
        }
        s.push(start);
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> topoSort(int V, vector<int>adj[]){

        int visited[V];
        memset(visited,0,sizeof(visited));
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i,s)
            }
        }        
    

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }

};