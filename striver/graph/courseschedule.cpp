class Solution
{
public:
    void addEdge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
    }

    void calculateIndegree(vector<int> adj[], int V, int indegree[])
    {
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adj[i])
            {
                indegree[itr]++;
            }
        }
    }

    bool kahnAlgoCyclic(vector<int> adj[], int indegree[], int V)
    {
        int count = V;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count--;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (count != 0)
            return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int e = prerequisites.size();

        vector<int> adj[numCourses];

        for (int i = 0; i < e; i++)
        {
            addEdge(adj, prerequisites[i][0], prerequisites[i][1]);
        }

        int indegree[numCourses];
        memset(indegree, 0, sizeof(indegree));

        calculateIndegree(adj, numCourses, indegree);

        return !kahnAlgoCyclic(adj, indegree, numCourses);
    }
};