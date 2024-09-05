class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n + m);    // Total sum of all n + m rolls
        int current_sum = accumulate(rolls.begin(), rolls.end(), 0);  // Sum of given rolls
        int missing_sum = total_sum - current_sum;  // Sum required for missing rolls

        // Check if it's possible to distribute the missing_sum to n dice
        if (missing_sum < n || missing_sum > 6 * n) {
            return {};  // No solution possible
        }

        // Initialize the missing array with all 1s (minimum value for each dice)
        vector<int> result(n, 1);
        missing_sum -= n;  // Remaining sum to distribute

        // Distribute the remaining sum as fairly as possible
        for (int i = 0; i < n && missing_sum > 0; ++i) {
            int add_value = min(5, missing_sum);  // Add at most 5 to each element (since 1 is already there)
            result[i] += add_value;
            missing_sum -= add_value;
        }

        return result;
    }
};
