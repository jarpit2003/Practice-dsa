class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        if (nums.size()<2)return nums.size();
       for(int i =2;i<nums.size();i++)
       {
         if(nums[k-1]!=nums[i]) 
         {
            nums[k+1] = nums[i];
            k++;
         }
         else continue;
       } 
       return k+1; 
    }
};