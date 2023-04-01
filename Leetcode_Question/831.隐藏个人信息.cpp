/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution {
public:
    string func1(string s) { // 如果邮件
        int n = s.size();

        vector<int> idx; // 记录 @ 和 . 出现的位置

        for (int i = 0; i < n; i ++) {
            if (s[i] == '@' || s[i] == '.') idx.push_back(i);
        }

        string res;

        res.push_back(tolower(s[0]));

        for (int i = 0; i < 5; i ++) {
            res.push_back('*');
        }

        res.push_back(tolower(s[idx[0] - 1]));
        res.push_back(s[idx[0]]);

        for (int i = idx[0] + 1; i < n; i ++) {
            res.push_back(s[i] == '.' ? '.' : tolower(s[i]));
        }


        return res;
    }

    string func2(string s) { // 如果是数字
        // 是数字只要获取后四位就可以了
        // 先把字符串中的数字提取出来
        vector<char> cnt;

        string res = "";

        for (int i = 0; i < s.size(); i ++) if (isdigit(s[i])) cnt.push_back(s[i]);

        // for (int i = 0; i < cnt.size(); i ++) cout << cnt[i] << ' ';

        int n = cnt.size();

        if (n == 13) res += "+***-";

        if (n == 12) res += "+**-";

        if (n == 11) res += "+*-";

        res += "***-***-";

        for (int i = n - 4; i < n; i ++) {
            res.push_back(cnt[i]);
        }

        return res;
    }

    string maskPII(string s) {
        // 首先是区分电子邮件和电话号码

        int idx = s.find("@");
        // cout << idx << endl;

        // return "a";
        return idx >= 0 ? func1(s) : func2(s);

    }
};
// @lc code=end

