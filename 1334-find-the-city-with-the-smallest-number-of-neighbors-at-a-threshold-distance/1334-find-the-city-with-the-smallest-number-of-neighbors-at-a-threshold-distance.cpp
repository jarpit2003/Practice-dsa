class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //convert to bidirectional garph
        //matrix banao usse updaye karo edges ke asath auyur ha diagonal bhi update kar dena
        //Floyd warshal lagao aur find out karte jao
        //mindistand result decalre karo satisfsy akaron ssari condition and cases
       
       vector<vector<int>>matrix(n,vector<int>(n,1e9)); for(auto&edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
           matrix[u][v] = wt;
           matrix[v][u] = wt;
        }
        
        for(int i =0;i<n;i++)
        {
            matrix[i][i] = 0;
        }
        for(int via =0;via<n;via++)
        {
            for(int i =0;i<n;i++)
            {
                for(int j =0;j<n;j++)
                {
                    if(matrix[i][via]!=1e9&&matrix[via][j]!=1e9)
                    {
                        if(matrix[i][via]+matrix[via][j]<matrix[i][j])
                        {
                            matrix[i][j] = matrix[i][via]+matrix[via][j];
                        }
                    }
                }
            }
        }
        int count = 0;
        int mindis = n+1;
        int city = -1;
         for(int i =0;i<n;i++)
            {
                for(int j =0;j<n;j++)
                {
                      if(matrix[i][j]<=distanceThreshold&&i!=j) count++;
                }
                if(count<=mindis)
                {
                mindis = count;
                city = i;
                }
                count = 0;
            }
            return city;
    }
};