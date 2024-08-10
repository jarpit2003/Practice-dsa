
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int count() {
        std::unordered_set<int> uniqueRoots;
        for (int i = 0; i < parent.size(); ++i) {
            uniqueRoots.insert(find(i));
        }
        return uniqueRoots.size();
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        UnionFind uf(4 * n * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int root = 4 * (i * n + j);
                if (grid[i][j] == ' ') {
                    // Union all parts of the cell
                    uf.unionSet(root + 0, root + 1);
                    uf.unionSet(root + 1, root + 2);
                    uf.unionSet(root + 2, root + 3);
                } else if (grid[i][j] == '/') {
                    // Union diagonally opposite parts
                    uf.unionSet(root + 0, root + 3);
                    uf.unionSet(root + 1, root + 2);
                } else if (grid[i][j] == '\\') {
                    // Union diagonally opposite parts
                    uf.unionSet(root + 0, root + 1);
                    uf.unionSet(root + 2, root + 3);
                }

                // Union with right neighbor
                if (j + 1 < n) {
                    uf.unionSet(root + 1, root + 4 + 3);
                }

                // Union with bottom neighbor
                if (i + 1 < n) {
                    uf.unionSet(root + 2, root + 4 * n + 0);
                }
            }
        }

        return uf.count();
    }
};
