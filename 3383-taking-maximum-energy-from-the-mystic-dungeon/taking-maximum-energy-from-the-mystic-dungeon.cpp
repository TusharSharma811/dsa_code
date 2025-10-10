class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int m = energy.size() ;
        vector<int> dp(m , 0) ;
        dp[m-1] = energy[m-1] ;
        for(int i=m-2 ; i>=0 ; i--){
            if(i+k >= m){
                dp[i] = energy[i] ;
            }
            else{
                dp[i] = energy[i] + dp[i+k] ;
            }
        }      
        int ans = INT_MIN ;
        for(int i=0 ; i<m ; i++){
            ans = max(ans,dp[i]) ;
        }

        return ans ;
    }
};