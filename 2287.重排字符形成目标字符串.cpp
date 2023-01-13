/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int res = 0;

        int al[26] = {0};

        for (int i = 0; i < s.size(); i ++) al[s[i] - 'a'] ++;

        while (1) {
            for (int i = 0; i < target.size(); i ++) {

                if (al[target[i] - 'a'] <= 0) return res; // 这里 break 只是跳出 for 里的循环

                else al[target[i] - 'a'] --;
            }

            res ++;
        }

        return res;
    }
};
// @lc code=end

