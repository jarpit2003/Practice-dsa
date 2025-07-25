class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(auto c:nums)
        {
            if(c==0) zero++;
            if(c==1) one++;
            if(c==2) two++;
        }
        for(int i =0;i<nums.size();i++)
        {
            if(zero>0)
            
            {
            nums[i] = 0;
            zero--;
            }
           else if(one>0)
            {
                nums[i] = 1;
                one--;
            }
            else if(two>0)
            {
                nums[i] = 2;
                two--;
            }
            else break;
        }
    }
};