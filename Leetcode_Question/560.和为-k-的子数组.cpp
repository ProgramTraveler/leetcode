/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 连续子数组
        unordered_map<int, int> mp;

        mp[0] = 1;
        int cnt = 0, pre = 0;

        for (auto& x : nums) {
            pre += x;

            if (mp.find(pre - k) != mp.end()) {
                cnt += mp[pre - k];
            }

            mp[pre] ++;
        }

        return cnt;

    }
};
// @lc code=end

