class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxif = 0;
        for(int i =0;i<nums.size();++i)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            maxif = max(maxif,count);
        }
        return maxif;
    }
};
