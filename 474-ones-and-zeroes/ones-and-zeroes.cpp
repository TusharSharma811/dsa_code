class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
          map<pair<int, int>, int> dp;
        dp[{0, 0}] = 0;

        for (auto &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            map<pair<int, int>, int> newdp;

            for (auto &[state, val] : dp) {
                int usedZero = state.first + zeros;
                int usedOne = state.second + ones;

                if (usedZero <= m && usedOne <= n) {
                    if (!dp.count({usedZero, usedOne}) || dp[{usedZero, usedOne}] < val + 1) {
                        newdp[{usedZero, usedOne}] = val + 1;
                    }
                }
            }

            for (auto &[state, val] : newdp) {
                dp[state] = max(dp[state], val);
            }
        }

        int ans = 0;
        for (auto &[_, val] : dp) ans = max(ans, val);
        return ans;
    }
};