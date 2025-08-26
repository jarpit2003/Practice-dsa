class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int count = -1;
        for(int  i =num.size()-1;i>=0;i--)
        {
            if(((num[i]-'0') % 2)!=0) 
            {
                count = i;
                break;
            }
        }
        if (count == -1) return ""; 
        for(int i =0;i<=count;i++)
        {
            ans.push_back(num[i]);
        }
        return ans;
    }
};