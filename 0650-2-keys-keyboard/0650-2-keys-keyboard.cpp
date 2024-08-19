class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0; // Base case: No operation needed for 1 'A'

        // dp[i] will hold the minimum number of operations to get 'A' exactly i times
        vector<int> dp(n + 1, 0);

        // Iterate over each number from 2 to n to fill dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = i; // Maximum operations is i (Copy 1 time, paste i-1 times)
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + (i / j); // If j is a factor, check using the smaller factor
                    dp[i] = min(dp[i], dp[i / j] + j); // Check using the larger factor
                    break; // As soon as we find the minimum operations, we can break
                }
            }
        }
        return dp[n];
    }
};