
typedef long long ll ;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<ll , ll> mpp ;
        for(auto elem : power){
            mpp[elem]++ ;
        }

       unordered_map<int , ll> dp ;
       ll ans =0 ;
       ll prevElem , backElem = 0 ;

       for(auto [el , fr] : mpp){
        auto backIt = mpp.lower_bound(el-2) ;
        if(backIt != mpp.begin()) {
            backIt-- ;
            backElem = backIt->first ;
        }

        dp[el] = max(dp[prevElem] , fr*el + dp[backElem]) ;
        ans= max(ans,dp[el]) ;
        prevElem = el ;
       }

       return ans ;
    }
};