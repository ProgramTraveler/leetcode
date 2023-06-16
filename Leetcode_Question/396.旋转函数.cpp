/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int res = INT_MIN;

        int n = nums.size();

        /* 超时了

        for (int i = 0; i < n; i ++) {
            int idx = 0, l = 0, r = i;
            int fun = 0;

            while (r < n) fun += idx * nums[r], idx ++, r ++; 
            while (l < i) fun += idx * nums[l], idx ++, l ++;

            res = max(fun, res);
        }*/

        // 迭代
        int func = 0;
        int numS = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i ++) func += i * nums[i];

        res = func;
        for (int i = n - 1; i >= 0; i --) {
            func += numS - n * nums[i];

            res = max(func, res);
        }

        return res;
    }
};
// @lc code=end

