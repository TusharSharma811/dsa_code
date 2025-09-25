class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
           int n = triangle.size() ;
        vector<vector<int>> dp(n , vector<int>(n+1 , 0)) ;
        for(int k=0 ; k<n ;  k++){
            dp[n-1][k]  = triangle[n-1][k] ;
        }
        for(int i=n-2 ; i>=0 ; i--){
            for(int j = 0 ; j<=i ; j++){
                int down = triangle[i][j] + dp[i+1][j] ;
                int diag = triangle[i][j] + dp[i+1][j+1] ;
                dp[i][j] = min(down , diag) ;
            }
        }

        return dp[0][0] ;
    }
};