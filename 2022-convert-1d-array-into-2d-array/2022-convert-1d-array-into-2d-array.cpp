class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return vector<vector<int>>();

        vector<vector<int>> arr;
        for (int row = 0; row < m; row++) {
            vector<int> hr(n, 0);
            for (int col = 0; col < n; col++) {
                hr[col] = original[row * n + col];
            }
            arr.push_back(hr);
        }

        return arr;
    }
};
