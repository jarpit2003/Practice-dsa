class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1'000'000'007;
        vector<long long int> subarraySums;

        // Calculate all possible subarray sums
        for (int i = 0; i < n; i++) {
            long long int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }

        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());

        // Calculate the sum of elements from `left` to `right` in the sorted array
        long long int answer = 0;
        for (int i = left - 1; i < right; i++) {
            answer = (answer + subarraySums[i]) % MOD;
        }

        return static_cast<int>(answer);
    }
};
