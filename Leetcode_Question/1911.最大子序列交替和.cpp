/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = nums[0], odd = 0;
        for (int i = 1; i < nums.size(); i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
        /*
            这样写的几乎都会超时 解决的方式几乎都是 dp
        
        long long res = 0;

        long long n1 = 0, n2 = 0;

        int n = 0; // 记录数字

        function<void(int)> dfs = [&](int i) {
            if (i >= nums.size()) {
                res = max(res, n2 - n1);

                return;
            }

            dfs(i + 1); // 不选

            n % 2 == 0 ? n2 += nums[i] : n1 += nums[i];
            n ++;

            dfs (i + 1);

            n --;
            n % 2 == 0 ? n2 -= nums[i] : n1 -= nums[i];

        };

        dfs(0);

        return res;
        */
    }
};
// @lc code=end

