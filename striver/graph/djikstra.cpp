  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>distance(V,INT_MAX);    
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        distance[S]=0;
        q.push(make_pair(0,S));
        
        while(!q.empty()){
            pair<int,int> node = q.top();
            q.pop();
            int dis = node.first;
            int u = node.second;
            
            for(auto v:adj[u]){
                int edgeWeight = v[1];
                int adjNode = v[0];
                if(distance[adjNode]==INT_MAX || dis+edgeWeight<distance[adjNode]){
                    distance[adjNode] = dis+edgeWeight;
                    q.push(make_pair(distance[adjNode],adjNode));
                }
            }
            
        }
        return distance;
        
    }