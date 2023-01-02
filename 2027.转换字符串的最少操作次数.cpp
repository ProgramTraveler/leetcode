/*
 * @lc app=leetcode.cn id=2027 lang=cpp
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minimumMoves(string s) { // 为什么不能从中间选？应该是选了操作次数是一样的
        int res = 0, idx = 0;

        while (idx < s.size()) {
            if (s[idx] == 'X') res ++, idx += 3;
            else idx ++;
        }
        
        return res;
    }
};
// @lc code=end

