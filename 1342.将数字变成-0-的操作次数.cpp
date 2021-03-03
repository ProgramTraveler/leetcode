/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while (num) {
            if (num & 1) num -= 1; //奇数就减去一
            else num >>= 1; //偶数就进行除二
            //操作次数加1
            res ++;
        }
        return res;
    }
};
// @lc code=end

