class Solution {
public:
    int maxDepth(string s) {
      int n = s.length();
        int count = 0;
        int ans = 0;
        stack<char>st;
     for(int i =0;i<n;i++)
     {
         if(s[i]=='(')
         {
             count++;
             st.push(s[i]);
             ans = max(ans,count);
         }
         if(s[i]==')')
         {
          count--;
             st.pop();
         }
      
         
         
         
     }
        return ans;
    }
};