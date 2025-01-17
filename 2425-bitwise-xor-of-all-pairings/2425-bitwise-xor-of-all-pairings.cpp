class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int counter = 0;
        if(n&1) {
            for(int i=0;i<m;i++) {
                counter^=nums2[i];
            }
        }
        if(m&1) {
            for(int i=0;i<n;i++) {
                counter^=nums1[i];
            }
        }
        return counter;
    }
};