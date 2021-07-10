/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        vector<int> num(26);
        for (char &ch : s) {
            num[ch - 'a']++;
        }

        string ret;
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
        }
        return ret;
    }
};

// @lc code=end

