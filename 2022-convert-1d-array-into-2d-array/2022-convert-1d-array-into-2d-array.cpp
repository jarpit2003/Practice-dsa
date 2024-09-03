class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // If the size doesn't match the required 2D array, return an empty vector
        if (original.size() != m * n) {
            return {};
        }

        // Preallocate the 2D array
        vector<vector<int>> arr2D(m, vector<int>(n));
        
        // Initialize row and column counters
        int row = 0, col = 0;
        
        // Fill the 2D array
        for (int i = 0; i < original.size(); ++i) {
            arr2D[row][col] = original[i];
            ++col;
            if (col == n) {
                col = 0;
                ++row;
            }
        }
        
        return arr2D;
    }
};
