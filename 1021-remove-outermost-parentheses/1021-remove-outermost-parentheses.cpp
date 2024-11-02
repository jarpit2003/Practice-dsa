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
           stack<char>st;
            string res = "";
            for(int i =0;i<n;i++)
            {
              
                if(s[i]==')'){st.pop();}
                if(!st.empty()){res.push_back(s[i]);}
                  if(s[i]=='('){st.push(s[i]);}
            }
        return res;
        }
        
    }
};