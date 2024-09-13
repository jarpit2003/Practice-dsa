class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> cumXor(n,0);
        
        // Build the prefix XOR array in one pass
        cumXor[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            cumXor[i] = cumXor[i - 1] ^ arr[i];
        }

        // Reserve space to avoid multiple reallocations in the result vector
        vector<int> result;
        result.reserve(queries.size());

        // Process queries
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // Compute XOR for the range [left, right]
            int xor_val = cumXor[right];
            if (left > 0) {
                xor_val ^= cumXor[left - 1];
            }
            
            // Store the result
            result.push_back(xor_val);
        }

        return result;
    }
};
