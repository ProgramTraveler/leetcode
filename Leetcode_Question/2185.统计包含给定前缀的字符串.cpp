/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {  // 就是简单的字符串比较 就是比较的函数有点忘了
        int res = 0;

        for (string s : words) {
            if (s.compare(0, pref.size(), pref) == 0) res ++;
        }

        return res;
    }
};
// @lc code=end

