/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
        string res;

        while (n) {
            int tem = n % (-2);

            res.push_back( '0' + abs(tem));

            // cout << tem << " ";

            n = tem < 0 ? n / (-2) + 1 : n / (-2);

            // cout << n << endl;
        }

        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};
// @lc code=end

