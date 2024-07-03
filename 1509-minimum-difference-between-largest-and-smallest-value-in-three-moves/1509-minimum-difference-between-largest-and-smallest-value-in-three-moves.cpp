
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        
        // Sort the first 4 and the last 4 elements
        partial_sort(begin(nums), begin(nums) + 4, end(nums));
        nth_element(begin(nums) + 4, begin(nums) + (n - 4), end(nums));
        sort(begin(nums) + (n - 4), end(nums));
        
        int result = INT_MAX;
        result = min(result, nums[n - 4] - nums[0]); // Change the three smallest elements
        result = min(result, nums[n - 1] - nums[3]); // Change the three largest elements
        result = min(result, nums[n - 2] - nums[2]); // Change the largest and two smallest elements
        result = min(result, nums[n - 3] - nums[1]); // Change the smallest and two largest elements
        
        return result;
    }
};