/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        //如果这个数除以质因数可以除到1，说明这个数是由质因数构成的
        while (num != 1) {
            if (num % 2 == 0) num = num / 2;
            else if (num % 3 == 0) num = num / 3;
            else if (num % 5 == 0) num = num / 5;
            else return false;
        }
        return true;
    }
};
// @lc code=end

