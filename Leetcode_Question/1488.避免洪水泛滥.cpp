/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // 也就是说只能在没有下雨的日子里抽干湖泊的水
        // 注意：当可以避免洪水时，晴天的日期赋值为 1
        // 注意：只能有水的时候才能抽
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> water; // 湖泊最近的下雨的日期
        set<int> zero; // 晴天

        for (int i = 0; i < rains.size(); i++) {
            int r = rains[i]; // 当前下雨的湖泊

            if (r == 0) {
                zero.insert(i);
                continue;
            }

            if (water.count(r) != 0) { // 湖泊再次下雨
                auto it = zero.lower_bound(water[r]);
                if (it == zero.end()) return {};
                ans[*it] = r;
                zero.erase(it);
            }
            water[r] = i;
            ans[i] = -1;
        }

        return ans;
    }
};
// @lc code=end

