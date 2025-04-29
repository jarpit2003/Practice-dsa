class Solution {
public:
vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int,int>>q;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1) 
                count++;
                if((i == 0||i==m-1||j == 0||j == n-1)&&grid[i][j] == 1)
                {
                q.push({i,j});
                grid[i][j] = 0;
                count--;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int>curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;
            for(auto dir:directions)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j] == 1)
                {
                    q.push({new_i,new_j});
                    grid[new_i][new_j] = 0; 
                    count--;
                }
            }
        }
        return count;
    }
};