class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mini = INT_MAX;
       int maxprof = 0;
       for(auto price:prices)
       {
        mini = min(price,mini);
        maxprof = max(maxprof,price-mini);
       }
       return maxprof;
     }   
    
};