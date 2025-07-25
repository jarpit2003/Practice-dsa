class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        vector<int>row;
        vector<int>col;
          for(int i =0;i<a;i++)
          {
            for(int  j = 0;j<b;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
          }
            for(auto &r:row)
            {
                for(int j = 0;j<b;j++)
                {
                  matrix[r][j] = 0;
                }
            }
              for(auto &c:col)
            {
                for(int i = 0;i<a;i++)
                {
                  matrix[i][c] = 0;
                }
            }
    }
};