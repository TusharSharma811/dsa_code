class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits1 = __builtin_popcount(num1), bits2 = __builtin_popcount(num2), res = num1;
        
        if (bits1 >= bits2) {
            while (bits1 > bits2) {
                res = res & (res - 1);
                bits1--;
            }
            return res;
        }

        else {
            while (bits1 < bits2) {
                res = res | (res + 1);
                bits1++;
            }
            return res;
        }
        return res;
    }
};