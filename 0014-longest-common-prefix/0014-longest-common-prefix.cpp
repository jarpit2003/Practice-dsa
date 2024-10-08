class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        string prefix = strs[0]; // Initialize with the first string
        
        // Compare the prefix with each subsequent string
        for (int i = 1; i < strs.size(); ++i) {
            // While the current string doesn't start with the prefix, keep reducing the prefix
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1); // Shorten the prefix
                if (prefix.empty()) {
                    return ""; // If prefix becomes empty, no common prefix exists
                }
            }
        }
        
        return prefix; // Return the longest common prefix after checking all strings
    }
};
