class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
         for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(i==0||j==0) dp[i][j] = 0;
                if(text1[i-1]==text2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
         }
     return dp[n][m];
    } 
    int longestPalindromeSubseq(string s) {
        string text1=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(text1,s);
    }
};