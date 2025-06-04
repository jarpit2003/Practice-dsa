class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>result;
        for(auto  &prerequisite:prerequisites)
        {
            int v = prerequisite[0];
            int u = prerequisite[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(numCourses,0);
        for(int i =0;i<numCourses;i++)
        {
            for(auto &p :adj[i])
            {
                indegree[p]++;
            }
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
       //3 simple bfs
       while(!q.empty())
       {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for(int &v :adj[curr])
        {
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
       }
       if(result.size()!=numCourses)
       {
        return {};
       }
       return result;
    }
};