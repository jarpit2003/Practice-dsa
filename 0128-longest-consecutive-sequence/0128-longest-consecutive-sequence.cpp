class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int curin = 1;
        int longin = 0;
        for(int i =0;i<nums.size()-1;i++)
        {
              if(nums[i]!=nums[i+1])
              {
                if(nums[i+1]-nums[i]==1) curin++;
                else 
              {
                longin = max(curin,longin);
                curin =1;
              }
              }
              
        }
        return max(longin,curin);
    }
};