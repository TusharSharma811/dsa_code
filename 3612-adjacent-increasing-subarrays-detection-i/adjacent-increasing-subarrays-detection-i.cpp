class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int flag = k-1;
        if(flag == 0)return true;
        for(int j=k+1;j<nums.size();j++){
            if(nums[j] > nums[j-1] && nums[j-k] > nums[j-k-1])flag--;
            else flag = k - 1;
            if(flag == 0)return true;
        }
        return false;
    }
};