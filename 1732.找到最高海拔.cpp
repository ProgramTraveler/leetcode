/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, idx = 0;

        for (int i = 0; i < gain.size(); i ++) res = max(res, idx + gain[i]), idx += gain[i];

        return res;
    }
};
// @lc code=end

