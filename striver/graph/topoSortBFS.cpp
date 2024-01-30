class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
    void calIndegree(int V, vector<int>adj[],vector<int>&indegree){
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                indegree[itr]++;
            }
        }
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int>indegree(V,0);
        calIndegree(V,adj,indegree);

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto itr:adj[node]){
                indegree[itr]--;
                if(indegree[itr]==0) q.push(itr);
            }
        }
        return ans;
	}
};