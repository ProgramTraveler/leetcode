/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
public:
    string decodeMessage(string key, string message) {
        // 感觉首先是需要去重的
        int ch[26] = {0}; // 记录一下 key 中每个字母出现的次数

        unordered_map<char, char> ma; // 记录出每个 key 对应的字母

        int idx = 0;

        for (char c : key) { // 注意处理空格
            if (c != ' ') {
                ch[c - 'a'] ++;

                if ((ch[c - 'a']) == 1) ma[c] = ('a' + idx), idx ++;
            }
        }
        //for (auto& [k, v] : ma) cout << k << ' ' << v << endl;

        string res = "";

        for (char c : message) {
            if (c == ' ') res += ' ';

            else res += ma[c]; 
        }

        return res;
    }
};
// @lc code=end

