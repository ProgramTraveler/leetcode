/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
class Solution {
public:
    string greatestLetter(string s) {
        int al1[26] = {0}, al2[26] = {0}; // 分别记录大小写字母出现的次数

        for (int i = 0; i < s.size(); i ++) {
            if (isupper(s[i])) al2[s[i] - 'A'] ++;

            if (islower(s[i])) al1[s[i] - 'a'] ++;
        }
        
        int idx = -1;

        for (int i = 0; i < 26; i ++) if (al1[i] > 0 && al2[i] > 0) idx = max(idx, i);

        char tem = 'A' + idx;

        string  res = "";

        if (idx >= 0) res = string(1, tem); // 字符转换为字符串
        
        return res;
    }
};
// @lc code=end

