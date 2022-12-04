/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start

/*
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
*/

class Solution {
public:
    void dfs (vector<int>& toppingCosts, int target, int cur, int &res, int p) {
        if (abs(res - target) < cur -target) return;

        if (abs(res - target) >= abs(cur - target)) {
            abs(res - target) > abs(cur - target) ? res = cur : res = min(res, cur);
        }

        if (p == toppingCosts.size()) return;

        dfs(toppingCosts, target, cur + toppingCosts[p] * 2, res, p + 1);
        dfs(toppingCosts, target, cur + toppingCosts[p], res, p + 1);
        dfs(toppingCosts, target, cur, res, p + 1);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = baseCosts[0];

        for (auto cur : baseCosts) dfs(toppingCosts, target, cur, res, 0);

        return res;
    }
};
// @lc code=end

