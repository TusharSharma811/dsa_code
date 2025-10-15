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
    int maxIncreasingSubarrays(vector<int>& nums) {
        int start = 1 ; 
        int end = nums.size()/2  ;
        int ans = INT_MIN ;
        while(start <= end){
            int mid = start + (end - start)/2 ;
            if(hasIncreasingSubarrays(nums , mid)){
                ans = max(ans , mid) ;
                start = mid+1  ;
            }
            else{
                end = mid-1 ;
            }
        }

        return ans ;
    }
};