class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        if(n == 0) return 0;
        int ans = 0;
        for(int c = 0;c<n;c++)
        {
            int l = c;
            int r = c;
            while(l<=r&&l>=0&&r<n&&s[l]==s[r])
            {
                 ans++;
                 l--;
                 r++;
            }
        }
        for(int c = 0;c<n;c++)
        {
            int l = c;
            int r = c+1;
            while(l<=r&&l>=0&&r<n&&s[l]==s[r])
            {
                 ans++;
                 l--;
                 r++;
            }
        }
        return ans;
    }
};