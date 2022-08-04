/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end()); //其实就是将原数组排序，每次都取最大的值
        int sum_1 = 0, sum_2 = 0;
        for (int i = 0; i < nums.size(); i ++) sum_1 += nums[i]; //求和
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (sum_2 <= sum_1) { 
                res.push_back(nums[i]);
                sum_2 += nums[i];
                sum_1 -= nums[i];
            } else break;
        }
        return res;
    }
};
// @lc code=end

