class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> openBrackets;  // Stack to store indices of '('
        std::string result;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openBrackets.push(result.size());
            } else if (s[i] == ')') {
                int start = openBrackets.top();
                openBrackets.pop();
                std::reverse(result.begin() + start, result.end());
            } else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};