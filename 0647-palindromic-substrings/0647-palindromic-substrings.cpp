class Solution {
public:
    bool ispal(string s)
    {
        bool flag = true;
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) 
            {
                flag = false;
               break;
            }
            ++i; --j;  
        }
        return flag;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i =0;i<s.size();i++)
        {
            for(int j = i;j<s.size();j++)
            {
                if(ispal(s.substr(i,j-i+1))) count++;
            }
        }
        return count;
    }
};