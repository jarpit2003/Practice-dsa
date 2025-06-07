class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adj(V);
         vector<int>indegree(V,0);
        queue<int>q;
        vector<int>result;
        for(int u =0;u<V;u++)
        {
        for(int v:graph[u])
        {
            adj[v].push_back(u);
        }
        indegree[u] = graph[u].size();
        }
         for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for(int &v:adj[curr])
        {
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
    }
    sort(result.begin(), result.end());
       return result;
    }
};