
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
        components = n;
    }

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]); // Path compression
    }

    void unionSets(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        if (xParent == yParent) {
            return;
        }
        if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        } else if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        } else {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
        components--;
    }

    bool isSingleComponent() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[0] > vec2[0];
        };
        sort(begin(edges), end(edges), lambda);

        int edgeCount = 0;
        for (auto& vec : edges) {
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if (type == 3) {
                bool edgeAdded = false;
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.unionSets(u, v);
                    edgeAdded = true;
                }
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.unionSets(u, v);
                    edgeAdded = true;
                }
                if (edgeAdded) {
                    edgeCount++;
                }
            } else if (type == 2) {
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.unionSets(u, v);
                    edgeCount++;
                }
            } else if (type == 1) {
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.unionSets(u, v);
                    edgeCount++;
                }
            }
        }

        if (Alice.isSingleComponent() && Bob.isSingleComponent()) {
            return edges.size() - edgeCount;
        }
        return -1;
    }
};
