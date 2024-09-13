class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       int n = arr.size();
        vector<int>cumXor(n,0);
        cumXor[0] = arr[0];
        for(int i =1;i<n;i++){
            cumXor[i] = cumXor[i-1]^arr[i];
        }
        vector<int> result;
        
        for (const auto& query : queries) {
            int temp1 = query[0];
            int temp2 = query[1];
            
          int xor_val = cumXor[temp2]^(temp1 == 0 ? 0: cumXor[temp1-1]);
            
            result.push_back(xor_val);
        }
        
        return result;
    }
};
