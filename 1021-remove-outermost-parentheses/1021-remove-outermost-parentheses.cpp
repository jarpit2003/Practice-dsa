class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        if(s.empty())
        {
            return s;
        }
        else
        {
           int count = 0;
            string res = "";
            for(int i =0;i<n;i++)
            {
                
                  if(s[i]==')'){count--;}
                if(count!=0){res.push_back(s[i]);}
              if(s[i]=='('){count++;}
            }
        return res;
        }
        
    }
};