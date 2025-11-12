class Solution {
public:
int gcd(int a , int b){
    if(a==0)return b ;
    return gcd(b%a,a) ;
}


    int minOperations(vector<int>& nums) {
          int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        if (ones > 0) return n - ones;
        int minLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g , nums[j]);
                if (g == 1) {
                    int len = j - i + 1;
                    minLen = min(minLen , len);
                    break;
                }
            }
        }

        if (minLen == INT_MAX) return -1;
        else return (minLen - 1) + (n - 1);
    }
};