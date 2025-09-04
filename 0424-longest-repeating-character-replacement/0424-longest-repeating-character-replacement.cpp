class Solution {
public:
    int characterReplacement(string s, int k) {
        int lt = 0;
        int maxlen = 0;
        int maxfreq = 0;
        vector<int>v(26,0);
        for(int rt =0;rt<s.size();rt++)
        {
         v[s[rt]-'A']++;
         maxfreq = max(maxfreq,v[s[rt]-'A']);
         while((rt-lt+1)-maxfreq>k)
         {
            v[s[lt]-'A']--;
            lt++;
         }
         maxlen = max(maxlen,rt-lt+1);
        }
        return maxlen;
    }
};