class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                return i;  // If the value doesn't match the index, return the missing number
            }
        }
        
        // If no missing number is found in the loop, it means the missing number is 'n'
        return n;
    }
};
