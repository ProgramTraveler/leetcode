/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
/*
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for (int i = 0; i < word1.size(); i ++)
            a += word1[i];
        for (int j = 0; j < word2.size(); j ++)
            b += word2[j];
        return a==b;
    }
};
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res_1 = "", res_2 = "";

        for (int i = 0; i < word1.size(); i ++) res_1 += word1[i];
        for (int i = 0; i < word2.size(); i ++) res_2 += word2[i];

        return res_1 == res_2;
    }
};
// @lc code=end

