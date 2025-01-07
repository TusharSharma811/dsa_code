class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ans;
        for (string& x : words) {
            for (string& y : words) {
                if (x != y && y.find(x) != string::npos) {
                    ans.insert(x);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};