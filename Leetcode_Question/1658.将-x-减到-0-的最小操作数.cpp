/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int n = nums.size();

        if (sum < x) return -1;

        int r = 0;

        int lsum = 0, rsum = sum;

        int res = n + 1;

        for (int l = -1; l < n; l ++) {
            if (l != -1) lsum += nums[l];

            while (r < n && (lsum + rsum) > x) rsum -= nums[r], r ++;

            if ((lsum + rsum) == x) res = min(res, l + 1 + n - r);
            
        }

        return res > n ? -1 : res;
    }
};
// @lc code=end

