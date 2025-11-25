class Solution {
public:
int roblinear(vector<int>& nums,int l,int r)
{
    int prev1 = 0;
    int prev2 = 0;
    for(int i =l;i<=r;i++)
    {
        int curr = max(prev1,prev2+nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
         if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        long case1 = roblinear(nums,0,n-2);
        long case2 = roblinear(nums,1,n-1);
        return (int)max(case1,case2);
    }
};