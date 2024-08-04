class Solution {
public:
    int minAddToMakeValid(string s) {
         int count = 0;
           int mount = 0;
       for(int i = 0;i<s.size();i++)
       {
          
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
           {
            count++;
           }
           else if(s[i]==')'||s[i]=='}'||s[i]==']')
           {
               if(count>0)
               {
                   count--;
               }
               else
               {
                   mount++;
               }
           }
       }
                   int output = abs(count+mount);
                   return output;
    }
};