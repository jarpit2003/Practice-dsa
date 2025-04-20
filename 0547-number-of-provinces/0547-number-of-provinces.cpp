class Solution {
public:
    void dfs(unordered_map<int, vector<int>> adj, int &u,
             vector<bool> &visited) {
                visited[u] = true;
                for(int &v : adj[u])
                {
                    if(!visited[v])
                    {
                        dfs(adj,v,visited);
                    }
                }
             }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int V = isConnected.size();
        for (int i = 0; i < V; i++) {
            for (auto j = 0; j != V;
                 j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);
        int count = 0;
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                dfs(adj, u, visited);
                count++;
            }
        }
        return count;
    }
};