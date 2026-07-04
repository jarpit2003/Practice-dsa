class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto ch:nums)
        {
            mp[ch]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto ch:mp)
        {
            pq.push({ch.second,ch.first});
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        
    }
};