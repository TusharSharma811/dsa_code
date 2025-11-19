class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin() , nums.end()) ;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == original){
                nums[i] = nums[i]*2 ;
                original = nums[i] ;
            }
        }
        return original ;
    }
};