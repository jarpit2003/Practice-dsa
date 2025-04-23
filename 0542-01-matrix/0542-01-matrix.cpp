class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // ✅ Initialize direction array (syntax fix)
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // ✅ Queue for BFS
        queue<pair<int, int>> q;

        // ✅ Step 1: Fill queue with 0s and mark 1s as -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1; // mark unvisited
                }
            }
        }

        // ✅ Step 2: BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                // ✅ Boundary and visited check
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && mat[new_x][new_y] == -1) {
                    mat[new_x][new_y] = mat[x][y] + 1; // distance from 0
                    q.push({new_x, new_y});
                }
            }
        }

        return mat;
    }
};
