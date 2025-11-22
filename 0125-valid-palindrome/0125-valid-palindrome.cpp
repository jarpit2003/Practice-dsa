class Solution {
public:
    bool isPalindrome(string s) {
        for (auto &c : s) {
            c = tolower(c);
        }
        string g;
        for(auto x:s)
        {
          if(isalnum(x)) g+=x;
          else continue;
        }
        int n = g.size();
        for(int i =0;i<g.size();i++)
        {
         if(g[i]==g[n-1-i]) continue;
         else return false;
        }
        return true;
    }
};