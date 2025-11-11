class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> ans(size(nums),1);
       int suffix = 1, prefix = 1, n = size(nums);
        for(int i = 0; i < n; i++) {
            ans[i] *= prefix;            
            prefix *= nums[i];			
            ans[n-1-i] *= suffix;         
            suffix *= nums[n-1-i];
        }
        return ans;
      
    }
};