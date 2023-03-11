/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) { // 还以为题解会有什么好方法
        int res = 1;

        for (auto n : nums) {
            if (n == 0) return 0;

            if (n < 0) res = - res;
        }

        return res;
    }
};
// @lc code=end

