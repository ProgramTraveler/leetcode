/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0; //特殊情况
        vector<int> nums(n + 1); // 构造一个模拟数组
        nums[1] = 1;
        for (int i = 2; i <= n; i ++) {
            nums[i] = nums[i / 2] + i % 2 * nums[i / 2 + 1];
        }
        return *max_element(nums.begin(), nums.end());
    }
};
// @lc code=end

