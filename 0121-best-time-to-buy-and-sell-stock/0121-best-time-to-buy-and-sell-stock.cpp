class Solution {
public:
int maxsum = 0;
    int maxProfit(vector<int>& prices) {
        for(int i =0;i<prices.size();i++)
        {
            for(int j = i+1 ;j<prices.size();j++)
            {
                maxsum = max(maxsum,prices[j]-prices[i]);
            }
        }
        return maxsum;
    }
};