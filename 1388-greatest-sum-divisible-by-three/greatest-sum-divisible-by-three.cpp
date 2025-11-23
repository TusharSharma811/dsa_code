class Solution {
public:

    int solve(vector<int>& nums , vector<vector<int>>& dp , int i , int rem){
        if(i==nums.size()){
            return rem == 0 ? 0 : INT_MIN ;
        }

        if(dp[i][rem] != -1) return dp[i][rem] ;

        int pick = nums[i] + solve(nums , dp , i+1 , (rem+nums[i])%3) ;
        int skip = solve(nums , dp , i+1 , rem) ;

        return dp[i][rem] = max(pick , skip) ;
     

    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n, vector<int>(3,-1)) ;
        return solve(nums , dp , 0 , 0 ) ;
    }
};