class Solution {
public:
    bool iscycledfs(int node,vector<bool>&visited,vector<bool>&ireccur,vector<vector<int>>&adjm)
    {
        visited[node] = true;
        ireccur[node] = true;
        int n = adjm[node].size();
        for(int neighbor=0;neighbor<n;neighbor++)
        {
            if(adjm[node][neighbor]==1)
            {
            if(visited[neighbor]==false&&iscycledfs(neighbor,visited,ireccur,adjm))
            {
                return true;
            }
            else if(ireccur[neighbor]==true)
            {
                return true;
            }
            }
            
        }
        ireccur[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjm(numCourses,vector<int>(numCourses,0));
        for(auto &prerequisite:prerequisites)
        {
            int v = prerequisite[0];
            int u = prerequisite[1];
            adjm[u][v] = 1; 
        }
        vector<bool>visited(numCourses,false);
        vector<bool>ireccur(numCourses,false);
        for(int i =0;i<numCourses;i++)
        {
            if(visited[i]==false&&iscycledfs(i,visited,ireccur,adjm))
            {
                return false;
            }
        }
            return true;
    }
};