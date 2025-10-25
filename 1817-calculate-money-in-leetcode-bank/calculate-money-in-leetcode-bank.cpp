class Solution {
public:
    int totalMoney(int n) {
         int week = n / 7;
        int day = n % 7;
        int rst = 28 * week + 7 * (week * (week - 1)) / 2;
        rst += ((week + 1) + (week + day)) * day / 2;
        return rst;
    }
};