class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }

        // Create the 2D vector and reserve memory for each row.
        vector<vector<int>> arr2D;
        arr2D.reserve(m); // Reserve memory for 'm' rows

        // Directly move elements from the original vector to the 2D array.
        for (int i = 0; i < m; ++i) {
            arr2D.push_back({original.begin() + i * n, original.begin() + (i + 1) * n});
        }

        return arr2D;
    }
};
