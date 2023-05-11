/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
    string func(int n) {
        string s;
        while (n) {
            s.push_back(n % 2 + '0');

            n /= 2;
        }

        reverse(s.begin(), s.end());
        
        return s;
    }

    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i ++) {
            string al = func(i);

            int idx = s.find(al, 0);

            if (idx < 0) return false;
        }

        return true;
    }
};
// @lc code=end

