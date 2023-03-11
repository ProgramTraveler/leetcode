/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class Solution {
public:
    int secondHighest(string s) { // 例子举得不好可以不举 1234 第二大应该是 3
        int fir = -1, sec = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int num = c - '0';

                if (num > fir) sec = fir, fir = num;
                else if (num < fir && num > sec) sec = num;
            }
        }

        return sec;
    }
};
// @lc code=end

