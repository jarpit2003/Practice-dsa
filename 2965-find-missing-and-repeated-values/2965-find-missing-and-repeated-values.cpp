class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeat = -1;
        int missing = -1;
        vector<int>freq(n*n+1,0);
        for(auto row:grid)
        {
            for(auto col:row)
            {
                freq[col]++;
            }
        }
        for(int num =1;num<=n * n;num++)
        {
            if(freq[num]==0) missing = num;
            else if(freq[num]==2) repeat = num;
        }
        return {repeat,missing};
    }
};