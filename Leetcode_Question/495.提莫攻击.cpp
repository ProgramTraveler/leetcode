/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, last = -1;
        for (int s : timeSeries) {
            int e = s + duration - 1;
            //对两次攻击是否重合的判断
            res += last < s ? duration : e - last;
            last = e;
        }
        return res;
    }
};
// @lc code=end

