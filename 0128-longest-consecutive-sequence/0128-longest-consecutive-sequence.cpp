class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
         unordered_set<int> st(nums.begin(), nums.end()); 
         int longconsnum = 0;
        for(auto num:st)
        {
           
            if(st.find(num-1)==st.end())
            {
                int currnum = num;
                int currconsnum =1;
                while(st.find(currnum+1)!=st.end())
                {
                    currnum++;
                    currconsnum ++;
                } 
                longconsnum = max(longconsnum,currconsnum);
            }
        }
        return longconsnum;
    }
};