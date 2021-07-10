/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            //x和后面的判断还是不要调换位置
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return res;
    }
};
// @lc code=end

