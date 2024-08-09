class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart, int cstart) {
        vector<vector<int>> directions = {
            {0, 1},   // move right
            {1, 0},   // move down
            {0, -1},  // move left
            {-1, 0}   // move up
        };
        vector<vector<int>> result;
        int steps = 0; // Start with 1 step
        int dir = 0;
        result.push_back({rstart, cstart});
        
        while (result.size() < rows * cols) {
            if (dir == 0 || dir == 2) { // Increase steps after completing horizontal moves (right or left)
                steps++;
            }
            for (int count = 0; count < steps; count++) {
                rstart += directions[dir][0];
                cstart += directions[dir][1];
                
                // Check if the new position is within bounds
                if (rstart >= 0 && rstart < rows && cstart >= 0 && cstart < cols) {
                    result.push_back({rstart, cstart});
                }
            }
            dir = (dir + 1) % 4; // Change direction
        }
        
        return result;
    }
};
