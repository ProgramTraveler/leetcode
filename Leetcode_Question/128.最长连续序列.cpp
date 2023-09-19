/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;

        set<int> cnt;

        for (auto n : nums) cnt.insert(n);

        for (auto n : cnt) {
            if (!cnt.count(n - 1)) { // 当前数没有前驱
                int current_n = n;
                int currentStreak = 1;

                while (cnt.count(current_n + 1)) { // 当前数有后驱
                    current_n += 1;

                    currentStreak ++;
                }

                res = max(currentStreak, res);
            }
        }

        return res;
    }
};
// @lc code=end

