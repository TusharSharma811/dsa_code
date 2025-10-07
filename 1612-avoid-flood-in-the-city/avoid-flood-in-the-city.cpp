class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
      int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> last; 
        set<int> zeros;             

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zeros.insert(i);
            } else {
                int lake = rains[i];
                if (!last.count(lake)) {
                    last[lake] = i;
                } else {
                    int prev = last[lake];
                    auto it = zeros.upper_bound(prev); 
                    if (it == zeros.end()) return {};
                    ans[*it] = lake;
                    zeros.erase(it);
                    last[lake] = i;
                }
            }
        }

        for (int idx : zeros) ans[idx] = 1;
        return ans;
    }
};