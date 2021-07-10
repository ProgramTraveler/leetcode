/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool> can(20001);
        for (int base : baseCosts)
            can[base] = true;
        toppingCosts.insert(toppingCosts.end(), toppingCosts.begin(), toppingCosts.end());
        for (int topping : toppingCosts) {
            for (int i = 20000; i >= topping; --i)
                can[i] = can[i] || can[i - topping];
        }
        int min_gap = INT_MAX, ans = 0;
        for (int i = 1; i <= 20000; ++i)
            if (can[i] && abs(i - target) < min_gap) {
                ans = i;
                min_gap = abs(i - target);
            }
        return ans;
    }
};
// @lc code=end

