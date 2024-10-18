class Solution {
public:
    long long minimumSteps(string s) {
        long long swap_count = 0;
        int one_count = 0;
        
        // Traverse the string from left to right
        for (char bit : s) {
            if (bit == '1') {
                one_count++;  // Count the number of '1's encountered
            } else if (bit == '0') {
                // When we encounter a '0', it has to move past all previous '1's
                swap_count += one_count;
            }
        }

        return swap_count;   
    }
};
