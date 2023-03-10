/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 移除的数组长度可以为空 说明需要先将数组求和
        // 注意数字溢出
        // 前缀和
        // 同余
        int n = nums.size(), res = n;

        long long s[n + 1];
        
        memset(s, 0, sizeof s);

        s[0] = 0;

        for (int i = 0; i < n; i ++) s[i + 1] = (s[i] + nums[i]) % p;//s[i + 1] = s[i] + nums[i];

        int x = s[n];

        //cout << x << ' ' << p << ' ' << (x %  p) << endl;

        if ((x % p) == 0) return 0; // 说明数组中的所有数字和都能被整除

        unordered_map<int, int> last;

        for (int i = 0; i <= n; i ++) {
            last[s[i] % p] = i;

            auto iter = last.find((s[i] - x + p) % p); //last.find((s[i] % p - x % p + p) % p);

            if (iter != last.end()) res = min(res, i - iter  -> second);
        }

        return res < n ? res : -1;
          
    }
};
// @lc code=end

