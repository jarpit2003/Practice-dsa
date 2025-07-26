class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j; 
        for(i = 0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(target == nums[i]+nums[j])
                {
                    return {i,j};
                }
                else
                {
                   
                }
               
            }
        
        }
         return {};
    }
    /*bool check()
    {

    }
vector<int>orignal=nums;
 sort(nums.begin(),nums.end());
 int left =  0;
 int right = nums.size()-1;
 while(left<right)
 {
     int sum = nums[left]+nums[right];
     if (sum == target)
     {
         int orignalleft = find(orignal.begin(),orignal.end(),nums[left])-orignal.begin();
         int orignalright = find(orignal.begin(),orignal.end(),nums[left])-orignal.begin();
         return {orignalleft,orignalright};
     }
     else if(sum<target)
     {
         left++;
     }
     else if(sum>target)
     {
         right--;
     }
 }
  return {};
    }
    */
 };