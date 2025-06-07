class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);   // Reverse graph
        vector<int> indegree(V, 0);   // Outdegree in original graph

        // Reverse the graph and compute outdegrees
        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                adj[v].push_back(u);  // Reverse edge
            }
            indegree[u] = graph[u].size();  // Outdegree of u
        }

        queue<int> q;
        vector<int> result;

        // Start with terminal nodes (outdegree 0)
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int v : adj[curr]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        sort(result.begin(), result.end());  // Required by the problem
        return result;
    }
};
