class Solution {
public:
int V ;
    void dfs(vector<vector<int>>& isConnected, int &u,
             vector<bool> &visited) {
               
                visited[u] = true;
                for(int v = 0;v<V;v++)
                {
                    if(!visited[v]&&isConnected[u][v]==1)
                    {
                        dfs(isConnected,v,visited);
                    }
                }
             }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
         V = isConnected.size();
        vector<bool> visited(V, false);
        int count = 0;
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                dfs(isConnected, u, visited);
                count++;
            }
        }
        return count;
    }
};