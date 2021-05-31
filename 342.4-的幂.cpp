/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        //是2的幂也会是4的幂
        //return n > 0 && (n & (n - 1)) == 0; //2的幂的判断方式
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
// @lc code=end

