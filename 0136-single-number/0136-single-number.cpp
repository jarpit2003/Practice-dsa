class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>singlenumber;
        for(int c:nums)
        {
          singlenumber[c]++;  
        }
        int answer = 0;
        for(int s:nums)
        {
            if(singlenumber[s]==1)
            {
             return s;
            }
        }
         return-1;
    }
};
