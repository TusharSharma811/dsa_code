class Solution {
public:
 bool isValid(vector<int>& nums, int count, int i, int direction) {
        vector<int> temp = nums;
        int idx = i;

        while (count > 0 && idx >= 0 && idx < nums.size()) {
            if (temp[idx] > 0) {
                temp[idx]--;
                direction = (-1) * direction;
                if (temp[idx] == 0) {
                    count--;
                }
            }
            idx += direction;
        }

        return count == 0; 
    }
    int countValidSelections(vector<int>& nums) {
         int result = 0;
        int count = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, count, i, -1)) {
                    result++;
                }
                if (isValid(nums, count, i, 1)) {
                    result++;
                }
            }
        }

        return result;
    }
};