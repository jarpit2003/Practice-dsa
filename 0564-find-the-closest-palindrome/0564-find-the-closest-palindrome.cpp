
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        
        // Edge cases: 10...01 and 999...999
        vector<string> candidates = {
            to_string((long long)pow(10, len - 1) - 1),  // Case like 999...999
            to_string((long long)pow(10, len) + 1)      // Case like 100...001
        };
        
        // Get the first half of the number
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        
        // Create palindromes by modifying the prefix
        for (long long i : {-1, 0, 1}) {
            string newPrefix = to_string(prefix + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.push_back(candidate);
        }
        
        // Find the closest palindrome
        string closest = "";
        long long minDiff = LLONG_MAX;
        
        for (string &candidate : candidates) {
            if (candidate == n) continue;
            long long candidateNum = stoll(candidate);
            long long diff = abs(candidateNum - num);
            
            if (diff < minDiff || (diff == minDiff && candidateNum < stoll(closest))) {
                minDiff = diff;
                closest = candidate;
            }
        }
        
        return closest;
    }
};