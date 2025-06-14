class Solution {
public:
typedef pair<long long,int>P;
const int MOD = 1'000'000'007;
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<vector<P>>adj(n);
      for(auto&road:roads)
      {
        int u =  road[0];
        int v = road[1];
        int time = road[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
      }
      priority_queue<P,vector<P>,greater<P>>pq;
      vector<long long>result(n,1e18);
      
      vector<int>ways(n,0);
      ways[0] = 1;
      int src = 0;
      result[src] = 0;
      pq.push({0,src});
      while(!pq.empty())
      {
        long long  ntime= pq.top().first;
        long long  nv = pq.top().second; 
        pq.pop();
        for(auto&neighbor:adj[nv])
        {
            long long newv = neighbor.first;
            long long newtime = neighbor.second;
            if(newtime+ntime<result[newv])
            {
                result[newv] = newtime+ntime;
                ways[newv] = ways[nv];
                pq.push({newtime+ntime,newv});
            }
            else if(newtime+ntime==result[newv])
            {
                ways[newv] = (ways[newv]+ways[nv])%(MOD);
            }
        }
      }
      return ways[n-1];
    }
};