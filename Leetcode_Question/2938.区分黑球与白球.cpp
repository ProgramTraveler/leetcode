/*
 * @lc app=leetcode.cn id=2938 lang=cpp
 *
 * [2938] 区分黑球与白球
 */

// @lc code=start
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int cnt1 = 0;
        for (char c : s) {
            if (c == '1') {
                cnt1++;
            } else {
                ans += cnt1;
            }
        }
        return ans;
    }
};
// @lc code=end

