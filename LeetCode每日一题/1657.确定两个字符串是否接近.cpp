/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        int m = word1.size();
        int n = word2.size();
        if (m != n)
            return false;
        vector<int> repeat1(26, 0), repeat2(26, 0);
        for (int i = 0; i < m; ++i)
        {
            ++repeat1[word1[i] - 'a'];
            ++repeat2[word2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if ((repeat1[i] == 0) ^ (repeat2[i] == 0))
                return false;
        sort(repeat1.begin(), repeat1.end());
        sort(repeat2.begin(), repeat2.end());
        for (int i = 0; i < 26; ++i)
            if (repeat1[i] != repeat2[i])
                return false;
        return true;
    }
};

// @lc code=end

