class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (const auto& query : queries) {
            int temp1 = query[0];
            int temp2 = query[1];
            int Xored = arr[temp1];
            
            // XOR all elements between temp1 and temp2 (inclusive)
            for (int j = temp1 + 1; j <= temp2; j++) {
                Xored ^= arr[j];
            }
            
            result.push_back(Xored);
        }
        
        return result;
    }
};
