class Solution {
public:

    int djikstra(int V, vector<vector<int>>adj[], int S, int D, int k){
        vector<int>distance(V,INT_MAX);

        // we cant use witgh as the first key in as it will just try ton minimise the cost and not the stops
        // there can be a case where the stops are less but the cost is more, and we may need to take that path, and djikstra will not conser that path
        // we need to use a pair of pair, where the first key is the stops and the second key is the cost,node
        // priority queue is not needed, as we visit the nodes, it is increasing the stops always, so we can just use a queue
        queue<pair<int,pair<int,int>>>q;
        distance[S]=0;
        q.push({0,{0,S}});

        while(!q.empty()){
            pair<int,pair<int,int>>fr = q.front();
            int stop = fr.first;
            int dis = fr.second.first;
            int u = fr.second.second;
            q.pop();
            for(auto v:adj[u]){
                    int edgeW = v[1];
                    int adjNode = v[0];
                    //relax

                    if(stop>k) continue;

                    if(dis+edgeW<distance[adjNode] && stop<=k){
                        distance[adjNode]=dis+edgeW;
                        q.push({stop+1,{dis+edgeW,adjNode}});
                    }

            }
        }
        return distance[D];
    }

    void addEdge(vector<vector<int>>adj[], int u, int v, int cost){
        vector<int>temp;
        temp.push_back(v);
        temp.push_back(cost);
        adj[u].push_back(temp);
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];

        for(int i=0;i<flights.size();i++){
            addEdge(adj,flights[i][0],flights[i][1],flights[i][2]);
        }

        int ans = djikstra(n, adj,src,dst,k);
        return ans==INT_MAX?-1:ans;
    }
};