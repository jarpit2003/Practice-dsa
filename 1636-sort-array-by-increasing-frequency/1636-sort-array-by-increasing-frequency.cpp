class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> frequency_map;
        for(int num : nums)
        {
            frequency_map[num]++;
        }
        sort(nums.begin(),nums.end(),[&](int a ,int b)
        {
            if(frequency_map[a] !=  frequency_map[b])
            {
               return frequency_map[a]< frequency_map[b];
            }
            return a > b;
        });
        return nums;
    }
};