/*
 * @lc app=leetcode.cn id=1750 lang=cpp
 *
 * [1750] 删除字符串两端相同字符后的最短长度
 */

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        char idx_l, idx_r;

        int l = 0, r = s.size() - 1;

        idx_l = s[l], idx_r = s[r];

        while (r > l && idx_l == idx_r) {

                while (s[l] == idx_l && l <= r) l ++;

                while (s[r] == idx_r && l <= r) r --;

                idx_l = s[l], idx_r = s[r];  
        }

        return r - l + 1;
    }
};
// @lc code=end

