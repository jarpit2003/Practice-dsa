class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int zerocount = 0;
        vector<int> res(nums.size(), 0);

        // Step 1: product of all non-zero numbers + zero count
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) pro *= nums[i];
            else zerocount++;
        }

        // Step 2: fill result
        for (int i = 0; i < nums.size(); i++) {
            if (zerocount > 1) {
                // more than 1 zero → all products are 0
                res[i] = 0;
            }
            else if (zerocount == 1) {
                // exactly 1 zero → only that zero position gets pro
                if (nums[i] == 0) res[i] = pro;
                else res[i] = 0;
            }
            else { 
                // no zeros → normal case
                res[i] = pro / nums[i];
            }
        }

        return res;
    }
};
