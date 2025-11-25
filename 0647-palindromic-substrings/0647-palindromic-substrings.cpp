class Solution {
public:
    int countSubstrings(string s) {
       int n = s.size();
       int cnt = 0;
       for(int center = 0;center<n;center++)
       {
        cnt+=expand(s,center,center);
        cnt+=expand(s,center,center+1);
       }
       return cnt;
    }
    int expand(string &s,int left,int right)
    {
        int cnt  = 0;
        while(left>=0&&right<s.size()&&s[left]==s[right])
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
};