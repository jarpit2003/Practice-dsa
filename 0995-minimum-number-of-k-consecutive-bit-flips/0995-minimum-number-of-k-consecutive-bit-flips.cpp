class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipcountbeforei = 0;
        vector<bool> isflipped(n, false);

        for (int i = 0; i < n; ++i) {
            if (i >= k && isflipped[i - k]) {
                flipcountbeforei--;
            }

            if ((flipcountbeforei % 2) == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipcountbeforei++;
                flips++;
                isflipped[i] = true;
            }
        }
        return flips;
    }
};