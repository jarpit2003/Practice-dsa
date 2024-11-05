class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        stack<char>st;
     for(int i =0;i<s.length();i++)
     {
         if(s[i]=='(')
         {
             count++;
             
             ans = max(ans,count);
         }
         if(s[i]==')')
         {
          count--;
             
         }
          if (count < 0) {
                    count = 0; 
                }
     }
        return ans;
    }
};