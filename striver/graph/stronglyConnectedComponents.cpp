#include <iostream>
using namespace std;

class Solution
{
private:
    void dfsSort(int node, vector<int> &vis, vector<int> adj[],stack<int> &st) {
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
private:
    void dfs(int node, vector<int> &vis, vector<int> adjT[]) {
        //normal dfs

    }
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[],vector<int> adjRev[]){
        // sort all vertices in finishing time
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsSort(i,vis,adj,st);
            }            
        }
        // make vi 0 again fir all
        //reverse the edges
        // already have

        //do a dfs from last finished node
        int ans=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs(node,vis,adjRev);
                ans++;
            }
        }

        return ans;
    }
};

int main() {

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int>adjRev[n];
    for (int i = 0; i < n; i++) {
        adjRev[edges[i][1]].push_back(edges[i][0]);
    }


    Solution obj;
    int ans = obj.kosaraju(n, adj,adjRev);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}