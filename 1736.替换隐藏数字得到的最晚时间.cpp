/*
 * @lc app=leetcode.cn id=1736 lang=cpp
 *
 * [1736] 替换隐藏数字得到的最晚时间
 */

// @lc code=start
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = ('4' <= time[1] && time[1] <= '9') ? '1' : '2';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};
// @lc code=end

