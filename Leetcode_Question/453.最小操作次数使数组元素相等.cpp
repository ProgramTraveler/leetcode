/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
       int minN = *min_element(nums.begin(), nums.end());

       int res = 0;

       for (int n : nums) res += n - minN;

       return res;
    }
};
// @lc code=end

