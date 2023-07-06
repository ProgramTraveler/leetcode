/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        // 一下没想到思路 其实挺简单的

        vector<long long> res;

        if (finalSum % 2 > 0) return res;

        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);

            finalSum -= i;
        }

        res.back() += finalSum;
        
        return res;
    }
};
// @lc code=end

