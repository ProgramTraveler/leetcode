/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = 0;
        string res = "";
        while (idx < word1.size() && idx < word2.size()) res += word1[idx], res += word2[idx], idx ++;
        
        if (idx < word1.size()) for (int i = idx; i < word1.size(); i ++) res += word1[i];

        if (idx < word2.size()) for (int i = idx; i < word2.size(); i ++) res += word2[i];

        return res;
    }
};
// @lc code=end

