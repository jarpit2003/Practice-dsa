class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lt = 0;
        int rt = 0;
        int zeros = 0;
        int out = 0;
        for(int rt =0;rt<nums.size();rt++)
        {
           if(nums[rt]==0)zeros++;
           while(zeros>k)
           {
            if(nums[lt]==0)zeros--;
            lt++;
           }
           out = max(out,rt-lt+1);
        }
        return out;
    }
};