class Solution {
public:
typedef pair<int,pair<int,int>>P;
vector<vector<int>>directions={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      if(m==0||n==0||grid[m-1][n-1]!=0||grid[0][0]!=0) return -1;
      priority_queue<P,vector<P>,greater<P>>pq;
      vector<vector<int>>result(m,vector<int>(n,1e9));
      result[0][0] = 1;
      pq.push({1,{0,0}});
      grid[0][0]=1;
      int dist = grid[0][0];
      while(!pq.empty())
      {
        int d = pq.top().first;
        pair<int,int>node = pq.top().second;
        int x = node.first;
        int y = node.second;
         pq.pop();
        for(auto&dir:directions)
        {
            int newx =x+dir[0];
            int newy =y+dir[1];
            dist = d+1;
           
            if(newx>=0&&newy>=0&&newx<m&&newy<n&&grid[newx][newy]==0&&d+1<result[newx][newy])
            {
                result[newx][newy] = dist;
                pq.push({d+1,{newx,newy}});
                grid[newx][newy] = 1;
            }
            if(newx==m-1&&newy==n-1&&result[newx][newy]!=1e9)
            {
                return d+1;
            }
        } 
      }
      return -1;
    }
};