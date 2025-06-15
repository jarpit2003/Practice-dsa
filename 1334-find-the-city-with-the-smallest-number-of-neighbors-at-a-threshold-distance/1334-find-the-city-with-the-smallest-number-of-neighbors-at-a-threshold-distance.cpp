class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        // Initialize distances
        for (int i = 0; i < n; ++i) matrix[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;  // Undirected
        }

        // Floyd-Warshall algorithm
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][via] != 1e9 && matrix[via][j] != 1e9)
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        int minReachable = n;  // Max possible
        int city = -1;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && matrix[i][j] <= distanceThreshold)
                    count++;
            }
            // If multiple cities have the same number of reachable cities, return the greatest number
            if (count <= minReachable) {
                minReachable = count;
                city = i;
            }
        }

        return city;
    }
};
