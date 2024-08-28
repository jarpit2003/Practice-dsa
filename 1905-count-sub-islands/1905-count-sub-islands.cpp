
class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
        // If out of bounds or at water in grid2, return true (nothing to invalidate)
        if (x < 0 || y < 0 || x >= grid2.size() || y >= grid2[0].size() || grid2[x][y] == 0)
            return true;
        
        // If this cell is land in grid2 but water in grid1, it's not a sub-island
        if (grid1[x][y] == 0)
            return false;
        
        // Mark the cell as visited by setting it to 0 in grid2
        grid2[x][y] = 0;
        
        // Explore all four directions and check if they are part of a sub-island
        bool up = dfs(grid1, grid2, x - 1, y);
        bool down = dfs(grid1, grid2, x + 1, y);
        bool left = dfs(grid1, grid2, x, y - 1);
        bool right = dfs(grid1, grid2, x, y + 1);
        
        // The current part of the island is valid only if all connected parts are valid
        return up && down && left && right;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslandsCount = 0;
        
        // Iterate through each cell in grid2
        for (int i = 0; i < grid2.size(); ++i) {
            for (int j = 0; j < grid2[0].size(); ++j) {
                // If the cell is land, check if it's part of a sub-island
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        subIslandsCount++;
                    }
                }
            }
        }
        
        return subIslandsCount;
    }
};