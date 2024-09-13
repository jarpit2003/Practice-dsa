class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        /* Declare a vector named result
        Design A SYSTEM such that querirs[i][.first,.second]
        calcute Xor and push in the array */
         vector<int>result;
        int temp1;
        int temp2;
        int Xored=arr[temp1];
        for(int i = 0;i<queries.size();i++)
        {
         temp1 = queries[i][0];
         temp2 = queries[i][1];
         Xored =  arr[temp1];
            for(int j = temp1+1;j<=temp2;j++)
            {
                Xored^=arr[j];
            }
         result.push_back(Xored);
        }
        return result;
    }
};