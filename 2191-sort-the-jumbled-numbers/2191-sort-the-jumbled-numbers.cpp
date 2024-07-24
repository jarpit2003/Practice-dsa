#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<long long, int>> mapped_nums(n);
        
        for (int i = 0; i < n; i++) {
            mapped_nums[i] = {getMappedValue(nums[i], mapping), i};
        }
        
        std::stable_sort(mapped_nums.begin(), mapped_nums.end());
        
        std::vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = nums[mapped_nums[i].second];
        }
        
        return result;
    }

private:
    long long getMappedValue(int num, const std::vector<int>& mapping) {
        if (num == 0) return mapping[0];
        
        long long mapped = 0;
        long long multiplier = 1;
        
        while (num > 0) {
            int digit = num % 10;
            mapped += (long long)mapping[digit] * multiplier;
            multiplier *= 10;
            num /= 10;
        }
        
        return mapped;
    }
};