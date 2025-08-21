class Solution {
public:
void dfs(int node, vector<int>&vis,int &n,vector<vector<int>>& isConnected)
{
    vis[node] = 1;
    for(int i =0;i<n;i++)
    {
        if(!vis[i]&&isConnected[node][i]) dfs(i,vis,n,isConnected);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m =  isConnected[0].size();
        int count = 0;
        vector<int>vis(n,0);
        for(int i = 0;i<n;i++)
        {
              if(!vis[i]) 
              {
                dfs(i,vis,n,isConnected);
                count ++;
              }
        }
        return count;
    }
};