/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
private:
    int rob(vector<int> &nums) {
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

public:
    int deleteAndEarn(vector<int> &nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};
// @lc code=end

