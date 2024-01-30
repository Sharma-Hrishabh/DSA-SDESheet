#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int spanningTree(int V, vector<vector<int>> adj[])
	{
        vector<pair<int,int>>mst;

        vector<int>visited(V,0);

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // weight, node, parent
        pq.push({0,{0,-1}});

        int sum=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            if(visited[node]==1) continue;

            // if not visited, add to sum, mark visit, add to mst
            sum += w;
            mst.push_back(make_pair(parent,node));
            visited[node]=1;

            //explore adjacent nodes

            for(auto it:adj[node]){
                int adjNode = it[0];
                int w = it[1];

                if(!visited[adjNode]){
                    pq.push({w,{adjNode,node}});
                }

            }
        }

        return sum;
        // return mst

	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}