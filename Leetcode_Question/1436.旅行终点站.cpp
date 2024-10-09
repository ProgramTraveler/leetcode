/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // 直接转成 map
        std::unordered_set<string> cites;
        for (int i = 0; i < static_cast<int>(paths.size()); i ++) {
            cites.insert(paths[i].front());
        }

        for (const auto& p : paths) {
            if (!cites.count(p.back())) {
                return p.back();
            }
        }

        return "";
    }
};
// @lc code=end

