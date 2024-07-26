class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Distance from a city to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Fill initial distances from the given edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distanceThreshold
        int minReachableCities = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            // If current city has fewer reachable cities, or in case of a tie, prefer the larger city index
            if (reachableCities < minReachableCities || (reachableCities == minReachableCities && i > resultCity)) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
