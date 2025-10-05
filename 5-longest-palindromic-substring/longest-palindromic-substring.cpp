class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];

        string ans = "";

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = gap + i;
                if (gap == 0) {
                    dp[i][j] = 1;
                } else if (gap == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {

                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                    } else {

                        dp[i][j] = 0;
                    }
                }

                if (dp[i][j] && (j - i + 1) > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};