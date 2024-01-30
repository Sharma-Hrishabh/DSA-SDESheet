class Solution{
    public:
    void generateGraph(string dict[],int N, int K, vector<int>adj[],vector<int>&indegree){
      for(int i=0;i<N-1;i++){
              string a = dict[i];
              string b = dict[i+1];
              int u = 0,v=0;
              while(a[u]==b[v] && u<a.size() && v<b.size()){
                  u++;
                  v++;
              }
              if(u<a.size() && v<b.size()) {
                adj[a[u]-'a'].push_back(b[v]-'a');   
                indegree[b[v]-'a']++;
              }
          
      }
    }
    

    
    string findOrder(string dict[], int N, int K) {
        //generate graph
        vector<int>adj[K];
        vector<int>indegree(K,0);
        generateGraph(dict,N,K,adj,indegree);
        
        string ans="";
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += (node+'a');
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return ans;
        
    }
};