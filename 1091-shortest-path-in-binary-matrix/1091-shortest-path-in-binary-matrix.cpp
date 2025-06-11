class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      //convert grid to graph using adjmatrix
      //ekc ount dexlare karo shortest ke liye
      //source i,j declare karo
      //dir banao diectionke liye  
      //loop bnao aur add karte jao pehle comapre karo ki bhai newi,newj ha vo 0 ha bhi ya ni agar ho toh usko na i+j ki form me max se store karvaolo jisnka sum max aaye usko leo
      //subsitut eko kardo vo i aur j ko naye vaale se
      //count++
      //return lkaro kya count
      //vector<vector<int>>adj[][] = grid;
      int n = grid.size();
      if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
    vector<vector<int>>directions={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    if(grid[0][0]!=0) return -1;
    if (n == 1 && grid[0][0] == 0) return 1;
    queue<pair<int, int>>q;
    q.push({0,0});
    grid[0][0] = 1;
   
    while(!q.empty())
    {
        auto[x,y] = q.front();
        int dist = grid[x][y];
        q.pop();
        for(auto&dir:directions)
        {
            int newx = x+dir[0];
            int newy = y+dir[1];
            if(newx==n-1&&newy==n-1)
            {
                return dist+1;
            }
            if(newx>=0&&newy>=0&&newx<n&&newy<n&&grid[newx][newy]==0)
            {
                q.push({newx,newy});
                grid[newx][newy] = dist + 1; 
            }
        }
    }
     return -1;
    }
};
