/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0, al[26] = {0};

        for (int i = 0; i < allowed.size(); i ++) al[allowed[i] - 'a'] ++; // 获取字母表

        for (auto st : words) {
            bool f = true;

            for (int i = 0; i < st.size(); i ++) if (al[st[i] - 'a'] <= 0) f = false;

            res += f ? 1 : 0; // 这一手我堪称无敌
        }

        return res;
    }
};
// @lc code=end

