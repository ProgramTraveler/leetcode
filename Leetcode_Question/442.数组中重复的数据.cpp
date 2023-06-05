/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>cnt;

        vector<int> res;

        for (auto &n : nums) {
            cnt[n] ++;

            if (cnt[n] >= 2) res.push_back(n);
        }

        return res;
    }
};
// @lc code=end

