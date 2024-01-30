#include<iostream>

using namespace std;

class Solution {
    void calIndegree(int V, vector<int>adj[],vector<int>&indegree){
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                indegree[itr]++;
            }
        }
    }
    vector<int> topologicalSort(int V, vector<int>adj[]){

        vector<int>indegree(V,0);
        calIndegree(V,adj,indegree);

        //contains nodes of only degree 0
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i)
        }
        vector<int>ans;
        while(!q.empty()){
            //remove front , add to ans, and remove its edges
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto itr:adj[node]){
                indegree[itr]--;
                // check if indegree is 0
                if(indegree[itr]==0) q.push(itr);
            }
        }
        return ans;
    }
}