/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;

        for (int i = 1; i < s.size(); i ++) {
            int sore = 0;

            for (int j = 0; j < i; j ++) if (s[j] == '0') sore ++;
            for (int j = s.size() - 1; j >= i; j --) if (s[j] == '1') sore ++;

            ans = max(sore, ans);
        }
        return ans;
    }
};
// @lc code=end

