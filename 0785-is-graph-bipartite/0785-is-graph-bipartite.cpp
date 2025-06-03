class Solution {
public:
    bool dfs(int node,vector<int>color,int c,vector<vector<int>>& graph)
    {
         color[node] = c;
        for(int neighbor:graph[node])
        {
            if(color[neighbor]==-1)
            {
                if(!dfs(neighbor,color,1-c,graph))
                {
                    return false;
                }
            }
            else if(color[neighbor]==c)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i =0;i<n;i++)
        {
          if(color[i]==-1)
          {
            if(!dfs(i,color,0,graph))
            {
                return false;
            }
          }
          
        }
        return true;
    }
};