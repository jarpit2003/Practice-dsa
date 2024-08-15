class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxif = 0, count = 0;
        
        for(int num : nums) {
            if (num == 1) {
                count++;
                maxif = max(maxif, count);
            } else {
                count = 0;
            }
        }
        
        return maxif;
    }
};
