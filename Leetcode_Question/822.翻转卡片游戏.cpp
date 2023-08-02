/*
 * @lc app=leetcode.cn id=822 lang=cpp
 *
 * [822] 翻转卡片游戏
 */

// @lc code=start
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        // 先翻转 可以翻转 任意张 卡片
        // 背面数字与任意一张正面数字都不相同（包括自己）才是符合题意
        // 吐槽一下题目 描述的太差了

        int res = INT_MAX;

        set<int> same; // 相同的数字

        int n = fronts.size();

        for (int i = 0; i < n; i ++) if (fronts[i] == backs[i]) same.insert(fronts[i]);

        // 正面
        for (int i = 0; i < n; i ++) if (same.count(fronts[i]) == 0) res = min(res, fronts[i]);
        
        // 反面
        for (int i = 0; i < n; i ++) if (same.count(backs[i]) == 0) res = min(res, backs[i]);

        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

