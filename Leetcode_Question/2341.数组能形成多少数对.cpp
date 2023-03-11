/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> al;

        for (int i = 0; i < nums.size(); i ++) al[nums[i]] ++;

        int sum = 0, n = nums.size();

        for (auto [k, v] : al) sum += v / 2, n -= (v / 2) * 2;
        

        return vector<int>{sum, n};
    }
};
// @lc code=end

