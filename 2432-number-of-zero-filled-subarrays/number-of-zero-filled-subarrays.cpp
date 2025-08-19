class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;

        long long int left = 0;
       long long int right = 0;

        while (left < n && right < n) {
            if (nums[left] != 0) {
                left++;
            } else if (nums[left] == 0) {
                right = left;
                while (right < n && nums[right] == 0 ) {
                    right++;
                }
                ans += (((right - left) * ((right - 1) - left + 2)) / 2 )*1LL;
                left = right;
            }
            
        }

        return ans;
    }
};