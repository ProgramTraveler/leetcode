/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 *
 * [3019] 按键变更的次数
 */

// @lc code=start
class Solution {
public:
    int countKeyChanges(string s) {
        int res = 0;

        for (int i = 0; i < static_cast<int>(s.size()) - 1; i ++) {
            if ((s[i + 1] - s[i]) % ('A' - 'a')) {
                res ++;
            }
        }

        return res;
    }
};
// @lc code=end

