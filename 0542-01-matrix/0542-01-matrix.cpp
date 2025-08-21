class Solution {
public:
typedef pair<int,int>p;
vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<p>q;
        for (int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(mat[i][j]==0)  
                {
                q.push({i,j});
                }  
                else mat[i][j] = -1;          
            }
        }
       while(!q.empty())
       {
        p curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        for(auto di:dir)
        {
            int newi = i+di[0];
            int newj = j+di[1];
            if(newi>=0&&newj>=0&&newi<m&&newj<n&&mat[newi][newj]==-1)
            {
                  
                    mat[newi][newj] = mat[i][j]+1;
                    q.push({newi,newj});
                  }
            }
        }     
        return mat;
    }
};