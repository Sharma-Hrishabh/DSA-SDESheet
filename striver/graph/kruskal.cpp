class DisjointSet{
    vector<int>size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
  
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                int u = i;
                int v= itr[0];
                int w = itr[1];
                edges.push_back({w,{u,v}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int ans = 0;
        DisjointSet ds(V);
        
        for(auto edge: edges){
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            // if u & v doesnt belong to same component
            if(ds.findUPar(u) != ds.findUPar(v)) {
                ans += w;   
                ds.unionBySize(u,v);
            }
            
            
        }
        return ans;
        
        
        
    }
};