/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
class Solution {
public:
    bool expend(string s, string tem) {
        int i = 0, j = 0; // s 和 tem 的初始坐标 也就是双指针

        while (i < s.size() && j < tem.size()) {
            if (s[i] != tem[j]) return false; // 当前字母不相等 直接返回 false

            char ch = s[i];

            int idx_i = 0; // 记录当前字母在 s 中出现的次数
            while (i < s.size() && s[i] == ch) idx_i ++, i ++;

            int idx_j = 0; // 记录当前字母在 tem 中出现的次数
            while (j < tem.size() && tem[j] == ch) idx_j ++, j ++;

            if (idx_j > idx_i) return false; // 如果 tem 出现的次数比 s 还多说明不满足扩张

            if (idx_i != idx_j && idx_i < 3) return false; // 不满足扩张长度要到 3 及以上的情况
        }

        return i == s.size() && j == tem.size();
    }

    int expressiveWords(string s, vector<string>& words) {
       int res = 0;

       for (auto &word : words) {
           if (expend(s, word)) res ++;
       }

       return res;
    }
};
// @lc code=end

