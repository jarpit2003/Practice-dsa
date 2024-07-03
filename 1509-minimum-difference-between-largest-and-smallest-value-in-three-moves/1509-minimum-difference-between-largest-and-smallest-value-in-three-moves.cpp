class Solution {
    private:

public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
    sort(begin(nums),end(nums));
        if(n<=3) 
        {
            return 0;
        }
        else
        {
        int result = INT_MAX;
        result = min(result,nums[n-4]-nums[0]);
        result = min(result,nums[n-1]-nums[3]);
        result = min(result,nums[n-2]-nums[2]);
        result = min(result,nums[n-3]-nums[1]);
        return result;
        }
    }
};