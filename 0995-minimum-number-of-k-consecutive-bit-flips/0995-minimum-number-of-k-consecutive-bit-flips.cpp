class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipcountFromPastfori = 0;
        vector<bool> isFlipped(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (i >= k && isFlipped[i - k]) {
                flipcountFromPastfori--;
            }
            
            if ((flipcountFromPastfori % 2 == 0 && nums[i] == 0) || (flipcountFromPastfori % 2 == 1 && nums[i] == 1)) {
                if (i + k > n) {
                    return -1;
                }
                
                flips++;
                flipcountFromPastfori++;
                isFlipped[i] = true;
            }
        }
        
        return flips;
    }
};
