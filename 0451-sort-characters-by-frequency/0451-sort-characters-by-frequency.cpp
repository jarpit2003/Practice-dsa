class Solution {
public:
    string frequencySort(string s) {
        if(s.empty())
        {
            return "";
        }
        else
        {
        unordered_map<char,int>map;
            for(int i =0;i<s.length();i++)
            {
              map[s[i]]++;
            }
            sort(s.begin(),s.end(),[&map](char a , char b) {
                if(map[a]==map[b])
                {
                    return a>b;
                }
                else
                {
                    return map[a]>map[b];
                }
               
            });
             return s;
        }
    }
};