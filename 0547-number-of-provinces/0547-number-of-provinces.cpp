class Solution {
public:
int n;
    void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited)
    {
        queue<int>q;
        q.push(u);
        visited[u] = true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int &v:adj[curr])
            {
             if(!visited[v])
             {
                bfs(adj,v,visited);
             }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(isConnected[i][j]==1&&i!=j)
              {
                adj[i].push_back(j);
                adj[j].push_back(i);
              }
            }
        }
        int count = 0;
        vector<bool>visited(n,false);
        for(int u = 0;u<n;u++)
        {
            if(!visited[u])
            {
                bfs(adj,u,visited);
                count++;
            }
        }
        return count;
    }
};