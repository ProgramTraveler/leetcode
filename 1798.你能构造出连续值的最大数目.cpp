/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 0;

        sort(coins.begin(), coins.end());

        for (int i : coins) {
            if (i > res + 1) break; // 如果当前的数字比 res + 1 都大 说明无法构造 res + 1

            res += i;
        }

        return res + 1;
    }
};
// @lc code=end

