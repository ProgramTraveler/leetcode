/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0, n = s.length(), m = t.length();
        for (int d = 1 - m; d < n; ++d) { // d=i-j, j=i-d
            int i = max(d, 0);
            for (int k0 = i - 1, k1 = k0; i < n && i - d < m; ++i) {
                if (s[i] != t[i - d])
                    k0 = k1, k1 = i;
                ans += k1 - k0;
            }
        }
        return ans;
    }
};
// @lc code=end

