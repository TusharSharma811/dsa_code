class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIndx = -1 ;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                if(lastIndx != -1 && i-lastIndx-1 < k){
                    return false ;
                }
                lastIndx = i ;
            }
        }
        return true ;
    }
};