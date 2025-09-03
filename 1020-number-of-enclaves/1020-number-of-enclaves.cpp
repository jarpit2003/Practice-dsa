class Solution {
public:
typedef pair<int,int>p;
vector<vector<int>>dir ={{0,1},{0,-1},{1,0},{-1,0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt  = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<p>q;
        for(int  i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1) 
                {
                    if(i==0||j==0||i==m-1||j==n-1) 
                    {
                        q.push({i,j});
                        cnt++;
                         grid[i][j] = 0;
                    }
                    else cnt++;
                }
            }
        }
        while(!q.empty())
        {
          p cur = q.front();
          int i= cur.first;
          int j = cur.second;
          q.pop();
          cnt--;
          for(auto d:dir)
          {
            int newi = i+d[0];
            int newj = j+d[1];
            if(newi>=0&&newi<m&&newj>=0&&newj<n&&grid[newi][newj]==1)
            {
                    q.push({newi,newj});
                    grid[newi][newj] = 0;
            }
          }
        }
        return cnt;
    }
};