class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> ans(spells.size());
        sort(potions.begin() , potions.end()) ;
        int maxPotion = potions[potions.size()-1] ;
        for (int i = 0; i < spells.size(); i++) {
            int spell = spells[i];
            long long k = (success + spell - 1) / spell;
            if (k <= maxPotion) {
                ans[i] =
                potions.size() - (lower_bound(potions.begin(), potions.end(), k) -
                         potions.begin());
            }
        }
        return ans ;
    }
};