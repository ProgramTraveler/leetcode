/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) { // 只包含 x 和 y
        int count[2] = {0};

        for (int i = 0, n = s1.size(); i < n; i ++) {
            if (s1[i] != s2[i]) count[s1[i] % 2] ++; // x 和 y 的 ascll 码不一样
        }

        int d = count[0] + count[1];

        return d % 2 != 0 ? -1 : d / 2 + count[0] % 2;
    }
};
// @lc code=end

