/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>m;
        for (int i = 0; i < nums.size(); i ++) {
            m[nums[i]] ++;
            if (m[nums[i]] > 1) return nums[i];
        }
        return 0;
    }
};
// @lc code=end

