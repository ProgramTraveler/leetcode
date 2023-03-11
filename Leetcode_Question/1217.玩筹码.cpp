/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;

        for (auto pos : position) {
            if (pos % 2 == 0) {
                odd ++;
            } else {
                even ++;
            }
        }

        return min(even, odd);

    }
};
// @lc code=end

