/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); //对数组进行排序

        int n = nums.size();

        for (int i = 1; i <= n; ++ i) {
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) return i;
        }

        return -1;
    }
};
// @lc code=end

