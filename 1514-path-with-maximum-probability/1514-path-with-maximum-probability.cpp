#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Step 1: Create the graph as an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        // Step 2: Use a priority queue to store {probability, node}, with the max probability on top
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        
        // Step 3: Vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        // Step 4: Modified Dijkstra's algorithm
        while (!pq.empty()) {
            auto [curProb, curNode] = pq.top();
            pq.pop();

            // If we reach the end node, return the probability
            if (curNode == end) {
                return curProb;
            }

            // Explore the neighbors
            for (auto& [nextNode, edgeProb] : graph[curNode]) {
                double newProb = curProb * edgeProb;
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        // If no path was found, return 0
        return 0.0;
    }
};
