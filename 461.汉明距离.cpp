/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int lowbit(int x) {
        return x & -x; 
    }
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = x ^ y; i > 0; i -= lowbit(i))
            res ++;
        return res;
    }
};
// @lc code=end

