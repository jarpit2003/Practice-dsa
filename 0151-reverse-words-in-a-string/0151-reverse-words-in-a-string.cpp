class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        string result;
        while (ss >> token) {
            result = token + " " + result;
        }
        // Remove trailing space from the result
        if (!result.empty()) {
            result.pop_back(); // Removes the last space
        }
        return result;
    }
};
