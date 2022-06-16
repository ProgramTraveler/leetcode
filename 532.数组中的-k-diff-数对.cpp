/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;

        for (auto& n : nums) {
            m[n] ++;
        }

        for (auto& [n, count]: m) { //关于对map之类的遍历方式不怎么熟练
            if (k == 0) {
                res += (count >= 2);
            } else {
                res += (m.count(n + k));
            }
        }
        
        return res;
    }
};
// @lc code=end

