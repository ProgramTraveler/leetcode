/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution {
public:
    int getLucky(string s, int k) {
        string res = "";

        for (char c : s)  res += to_string(c - 'a' + 1);

        for (int i = 1; i <= k && res.size() > 1; i ++) {
            int sum = 0;

            for (char c : res) sum += c - '0';

            res = to_string(sum);
        }

        return stoi(res);
    }
};
// @lc code=end

