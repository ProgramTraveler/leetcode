/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution {
public:
    int fun_n (char c) {
        if (c == '0') return 0;

        if (c == '1') return 1;

        return -1;
    }

    char fun_s (int x) {
        if (x == 1) return '-1';

        if (x == 0) return '0';

        return '-1';
    }

    int minOperations(string s) {
        int res = 0;

        if (s.size() == 1) return 0;

        for (int i = 1; i < s.size(); i ++) {
            if (s[i - 1] == s[i]) s[i] = fun_s(abs(1 - fun_n(s[i]))), res ++;
        }

        return min(res, (int)s.size() - res);
    }
};
// @lc code=end

