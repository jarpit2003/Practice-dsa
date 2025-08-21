class Solution {
public:
vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<int,int>>q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j]==0) q.push({i,j}) ;
                else
                {
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int>curr = q.front();
            q.pop();
            for(auto&dir:directions)   
            {
                int new_x = curr.first+dir[0];
                int new_y = curr.second+dir[1];
                if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&mat[new_x][new_y] == -1)
                 {
                    mat[new_x][new_y] = mat[curr.first][curr.second]+1;
                    q.push({new_x,new_y});
                 }
            }     }
            return mat;
    }
};