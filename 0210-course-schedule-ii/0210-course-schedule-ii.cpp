class Solution {
public:
   bool iscycledfs(int node,vector<bool>&visited,vector<bool>&ireccur,vector<int>&result,vector<int>adj[])
   {
    visited[node] = true;
    ireccur[node] = true;
    
    for(auto neighbor:adj[node])
    {
        if(visited[neighbor]==false&&iscycledfs(neighbor,visited,ireccur,result,adj))
        {
            return true;
        }
        else if(ireccur[neighbor]== true)
        {
            return true;
        }
    }
    ireccur[node] = false;
    result.push_back(node);
    return false;;
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(const auto prerequisite:prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>inreccur(numCourses,false);
        vector<int>result;
        for(int i =0;i<numCourses;i++)
        {
        if(visited[i]==false&&iscycledfs(i,visited,inreccur,result,adj))
        {
            return {};
        }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};