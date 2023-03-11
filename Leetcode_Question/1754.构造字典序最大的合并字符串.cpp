/*
 * @lc app=leetcode.cn id=1754 lang=cpp
 *
 * [1754] 构造字典序最大的合并字符串
 */

// @lc code=start
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int l = 0, r = 0;

        string res = "";

        while (l < word1.size() || r < word2.size()) {
            if (l < word1.size() && word1.substr(l) > word2.substr(r)) res.push_back(word1[l ++]);
            else res.push_back(word2[r ++]);
        }

        return res;

        /*
        最初的解法没有考虑到当两个字母相同时应该优先放入的是哪个字母 而且循环也比较冗长

        int l = 0, r = 0;

        string res = "";

        while (l < word1.size() && r < word2.size()) {
            if (word1[l] > word2[r]) res += word1[l], l ++;
            else res += word2[r], r ++;
        }

        while (l < word1.size()) res += word1[l], l ++;
        while (r < word2.size()) res += word2[r], r ++;

        return res;
        */
    }
};
// @lc code=end

