/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //每次把最小的数字取反，耗时感人
        sort(nums.begin(), nums.end()); //将数组从小到大排序
        for (int i = 0; i < k; i ++) {
            nums[0] = -nums[0]; //对最小的数取反，排序后最小的肯定是在首位
            sort(nums.begin(), nums.end()); //每次取反后重新排序
        }
        //k次取反后对数组简单求下和
        int res = 0, i = 0;
        while (i < nums.size()) {
            res += nums[i];
            i ++;
        }
        return res;
    }
};
// @lc code=end

