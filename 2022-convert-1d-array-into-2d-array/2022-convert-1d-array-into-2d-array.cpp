class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        /*#vector 2d array vala declare kardo
        #loop lgao avoid karo 2 loop lagana
        # 2d array banao aur return karavaao*/
        if(original.size()!=m*n)
        {
            return {};
        }
        vector<vector<int>>arr2D(m,vector<int>(n));
        for(int i =0;i<original.size();i++)
        {
            arr2D[i / n][i % n] = original[i];
        }
        return arr2D;
    }
};