/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) { // s 同时作为栈
        // 太巧妙了
        int i = 0; // i - 1 表示栈顶下标 i = 0 表示栈为空

        for (char c : s) {
            if (c > 'a' && (i == 0 || c - s[-- i] != 1)) return false;

            if (c < 'c') s[i ++] = c; // 入栈
        }

        return i == 0;
    }
};
// @lc code=end

