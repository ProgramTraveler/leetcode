/*
 * @lc app=leetcode.cn id=1785 lang=cpp
 *
 * [1785] 构成特定和需要添加的最少元素
 */

// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) { // 算法思想
        long long sum = 0;

        for (int i = 0; i < nums.size(); i ++) sum += nums[i]; // 先求出已知和

        long long diff = abs(sum - goal);

        return (diff + limit - 1) / limit;

    }
};
// @lc code=end

