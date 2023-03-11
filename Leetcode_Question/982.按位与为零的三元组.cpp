/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& nums) { // 暴力枚举肯定会超时
        // 这个思路可以 将三次循环简化成两次循环
        unordered_map<int, int> al;

        int res = 0;

        for (int x : nums) {
            for (int y : nums) {
                al[x & y] ++;
            }
        }

        for (auto [k, v] : al) {
            for (int i = 0; i < nums.size(); i ++) {
                res += (k & nums[i]) == 0 ? v : 0;
            }
        }

        return res;

    }
};
// @lc code=end

