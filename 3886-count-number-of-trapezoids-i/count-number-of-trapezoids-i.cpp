class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long int MOD = 1e9 + 7 ;
        map<int , int> mpp ;
        for(auto point : points){
            mpp[point[1]]++ ;
        }
       
        long long int r = 0 , ans = 0 ;
        for(auto [level , count] : mpp){
            if(count >= 2){
               long long c = count % MOD;
                long long w = (c * ((c - 1 + MOD) % MOD)) % MOD;
                w = (w * ((MOD + 1) / 2)) % MOD;   
                r = (r + (w * ans) % MOD) % MOD;
                ans = (ans + w) % MOD;
            }
        }

        return r%MOD ;
    }
};