class Solution {
    typedef pair<int,int>P;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&neighbor:times)
        {
            int u = neighbor[0];
            int v = neighbor[1];
            int cost = neighbor[2];
            adj[u].push_back({v,cost});
        }
       priority_queue<P,vector<P>,greater<P>>pq;
       vector<int>result(n+1,1e9);
       result[k] = 0;
       pq.push({0,k});
       while(!pq.empty())
       {
        int cost = pq.top().first;
        int nodet = pq.top().second;
        pq.pop();
        for(auto&neighbor:adj[nodet])
        {
            int newtar = neighbor.first;
            int newcost = neighbor.second;
            if(cost+newcost<result[newtar])
        {
           
            pq.push({cost+newcost,newtar});
            result[newtar] =cost+newcost;
        }
        }
        
       } 
       int maxi =0;
       for(int i =1;i<=n;i++)
       {
        maxi = max(result[i],maxi);
       }
       if(maxi==1e9) return -1;
       return maxi;
    }
};