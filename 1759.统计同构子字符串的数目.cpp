/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 */

// @lc code=start
class Solution {
public:
    typedef long long LL;

    int countHomogenous(string s) { // 对数学公式的利用 其实还是对字符串以及子串的关系 long long 和 int 的区别？
        LL res = 0;

        LL mod = 1e9 + 7; // 大数取余

        char idx = s[0]; // 标签字母

        int cnt = 0;

        for (char c : s) {
            if (c == idx) cnt ++;

            else {
                res += (LL) cnt * (cnt + 1) / 2;

                idx = c;

                cnt = 1;
            }
        }
        res += (LL) cnt * (cnt + 1) / 2;

        return res % mod;
    }
};
// @lc code=end

