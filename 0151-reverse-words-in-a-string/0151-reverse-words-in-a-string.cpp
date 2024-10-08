class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string first
        reverse(s.begin(), s.end());
        
        int i = 0;
        int l = 0;  // Start of the word
        int r = 0;  // End of the word
        int n = s.length();
        
        while (i < n) {
            // Skip leading spaces
            while (i < n && s[i] == ' ') i++;
            
            // Now `i` points to the start of a word
            l = r;
            
            // Copy the word to the correct position (overwriting leading spaces)
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }
            
            // Reverse the word we just copied
            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                // Add a space after the word if it's not the last word
                if (r < n) {
                    s[r++] = ' ';
                }
            }
            
            // Skip trailing spaces after the word
            while (i < n && s[i] == ' ') i++;
        }
        
        // Remove the trailing space if necessary
        if (r > 0 && s[r - 1] == ' ') {
            r--;
        }
        
        // Trim the string to remove extra characters at the end
        s = s.substr(0, r);
        
        return s;
    }
};
