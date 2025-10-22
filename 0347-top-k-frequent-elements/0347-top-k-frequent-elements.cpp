class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num:nums) mp[num]++;
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b)
        {
            return a.second>b.second;
        });
        vector<int>result;
        for(int i =0;i<k&&i<vec.size();i++)
        {
            result.push_back(vec[i].first);
        }
        return result;
    }
};