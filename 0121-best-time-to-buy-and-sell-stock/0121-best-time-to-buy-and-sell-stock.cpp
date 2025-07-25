class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdif = 0;
        int n = prices.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1 ;j<n;j++)
            {
                maxdif = max(maxdif,(prices[j]-prices[i]));
            }
        }
        return maxdif;
    }
};