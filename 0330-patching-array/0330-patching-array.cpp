
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach = 0;  // The largest number that can be formed
        int patches = 0, i = 0;

        while (reach < n) {
            if (i < nums.size() && nums[i] <= reach + 1) {
                reach += nums[i++];
            } else {
                reach += reach + 1;
                patches++;
            }
        }

        return patches;
    }
};
