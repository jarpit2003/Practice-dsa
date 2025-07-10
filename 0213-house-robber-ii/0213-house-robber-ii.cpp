class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i =2;i<=n-1;i++)
        {
            dp[i] = max(dp[i-1],nums[(i-1)]+dp[i-2]);
        }
       int result1 = dp[n-1];
       dp.clear();
       dp[0] = 0;
       dp[1] = 0;
       for(int i =2;i<=n;i++)
        {
            dp[i] = max(dp[i-1],nums[(i-1)]+dp[i-2]);
        }
        int result2 = dp[n];
        return max(result1,result2);
    }
};