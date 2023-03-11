/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution {
public:
    int countEven(int num) {
        int res = 0, idx = 1;

        while (idx <= num) {
            int tem = 0, idx_tem = idx;

            while (idx_tem) tem += idx_tem % 10, idx_tem /= 10;
            
            res += tem % 2 == 0 ? 1 : 0;

            idx ++;
        }
 
        return res;
    }
};
// @lc code=end

