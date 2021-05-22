/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }
        int xorsum = 0;
        for (int num : nums) {
            xorsum ^= num;
        }
        return xorsum == 0;
    }
};
// @lc code=end

