/*
 * @lc app=leetcode.cn id=2293 lang=cpp
 *
 * [2293] 极大极小游戏
 */

// @lc code=start
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[n - 1];

        vector<int> res(n / 2, 0); // 构造新数组

        for (int i = 0; i < n / 2; i ++) res[i] = i % 2 == 0 ? min(nums[i * 2], nums[i * 2 + 1]) : max(nums[i * 2], nums[i  * 2 + 1]);
        
        return minMaxGame(res); // 有返回值
    }
};
// @lc code=end

