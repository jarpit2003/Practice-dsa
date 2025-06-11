class Solution {
public:
vector<vector<int>>directions={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
typedef pair<int,pair<int,int>>P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        if(n==0||m==0||grid[n-1][m-1]!=0||grid[0][0]!=0) return -1;
        vector<vector<int>>result(n,vector<int>(n,1e9));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        result[0][0] = 0;
        while(!pq.empty())
        {
            int d = pq.top().first;
            pair<int,int>node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(auto dir : directions)
            {
                int newx = x+dir[0];
                int newy = y+dir[1];
                int dist = 1;
                if(newx>=0&&newx<n&&newy>=0&&newy<m&&grid[newx][newy]==0&&d+dist<result[newx][newy])
                {
                    pq.push({d+dist,{newx,newy}});
                    result[newx][newy] = d+dist;
                }
            }
        }
        if(result[n-1][m-1]==INT_MAX) return -1;
        return result[n-1][m-1]+1;
    }
};