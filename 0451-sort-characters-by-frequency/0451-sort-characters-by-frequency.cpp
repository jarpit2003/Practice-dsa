class Solution {
public:
    string frequencySort(string s) {
        int freq[128];
        for(char c:s)
        {
            freq[c]++;
        }
        sort(s.begin(),s.end(),[&](char a, char b)
         { if(freq[a]==freq[b]) return a>b;
           return freq[a]>freq[b];
         }
        );
        return s;
    }
};