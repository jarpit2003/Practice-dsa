class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(const string& s:arr)
        {
           freq[s]++; 
        }
        int distinctCount=0;
        for(const string& s : arr)
        {
            if(freq[s] == 1)
            {
                distinctCount++;
                if(distinctCount == k)
                {
                    return s;
                }
            }
        }
        return "";
    }
};