/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> Min_R(n); // 维持当前下标右数组的最小数
        Min_R[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i --) Min_R[i] = min(Min_R[i + 1], nums[i]);

        int Max_L = INT_MIN; 

        for (int i = 0; i < n - 1; i ++) {
            Max_L = max(Max_L, nums[i]);

            if (Max_L <= Min_R[i + 1]) return i + 1; // 如果比当前的右数组小 说明比后面的都小
        }

        return n - 1;

    }
};
// @lc code=end

