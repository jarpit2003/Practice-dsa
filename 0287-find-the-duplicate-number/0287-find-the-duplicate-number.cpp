class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int number = 0;
        for(int i = 0;i<n-1;i++)
        {
           
            if(nums[i]==nums[i+1])
            {
                number = nums[i];
                break;
            }
        }
        return number;
    }
};