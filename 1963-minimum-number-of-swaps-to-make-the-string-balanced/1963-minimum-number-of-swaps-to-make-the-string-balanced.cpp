class Solution {
public:
    int minSwaps(string s) {
        int N = s.size(), cnt = 0, j = N - 1, ans = 0;
        for (int i = 0; i < j; ++i) {
            cnt += s[i] == '[' ? 1 : -1;
            if (cnt == -1) { // found an unmatched `]`
                while (s[j] == ']') --j; // swap with the rightmost `[`
                cnt = 1;
                ++ans;
            }
        }
        return ans;
    }
};