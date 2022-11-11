/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        string s_l = s.substr(0, s.size() / 2);
        string s_r = s.substr(s.size() / 2);

        int res_l = 0, res_r = 0;

        cout << s_l << " " << s_r << endl;

        for (int i = 0; i < s_l.size(); i ++) if (s_l[i] == 'a' || s_l[i] == 'A' || s_l[i] == 'e' || s_l[i] == 'E' || s_l[i] == 'i' || s_l[i] == 'I' || s_l[i] == 'o' || s_l[i] == 'O' || s_l[i] == 'u' || s_l[i] == 'U') res_l ++;

        for (int i = 0; i < s_r.size(); i ++) if (s_r[i] == 'a' || s_r[i] == 'A' || s_r[i] == 'e' || s_r[i] == 'E' || s_r[i] == 'i' || s_r[i] == 'I' || s_r[i] == 'o' || s_r[i] == 'O' || s_r[i] == 'u' || s_r[i] == 'U') res_r ++;

        cout << res_l << ' ' << res_r << endl;

        return res_l == res_r;

    }
};
// @lc code=end

