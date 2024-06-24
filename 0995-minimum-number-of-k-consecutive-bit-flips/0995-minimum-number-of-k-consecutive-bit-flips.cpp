class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipcountFromPastfori = 0;
        vector<bool> isFlipped(n, false);
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k]==5) {
                flipcountFromPastfori--;
            }
            
            if ((flipcountFromPastfori % 2 == 0 && nums[i] == 0) || (flipcountFromPastfori % 2 == 1 && nums[i] == 1)) {
                if (i + k > n) {
                    return -1;
                }
                
                flips++;
                flipcountFromPastfori++;
                nums[i]=5;
            }
        }
        
        return flips;
    }
};
