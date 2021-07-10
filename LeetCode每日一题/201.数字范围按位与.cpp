/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
//关键还是找公共的前缀
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int shift = 0;
        // 相等的时候找到公共前缀
        while (m < n) 
        {
            m >>= 1;
            n >>= 1;//各自右移一位并赋值
            shift++;
        }
        return m << shift;
    }
};
// @lc code=end

