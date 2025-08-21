class Solution {
public:
typedef pair<int,int>p;
        vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int col = image[sr][sc];
        image[sr][sc] = color;
        if (col == color) return image;
        queue<p>q;
        q.push({sr,sc});
               
        while(!q.empty())
        {
            int N = q.size();
            while(N--)
            {
                p curr = q.front();
                q.pop();
                //change colour jo pop kiya ha
                int i = curr.first;
                int j = curr.second;
                for(vector<int>&dir:directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&image[new_i][new_j]==col)
                    {
                        q.push({new_i,new_j});
                        image[new_i][new_j] = color;
                    }
                }
            }
            
        }
        return image;
    }
};