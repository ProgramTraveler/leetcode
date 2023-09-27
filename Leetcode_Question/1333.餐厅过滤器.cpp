/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;

        vector<vector<int>> res_vegenF;
        // 先把素食者友好的餐厅选出来
        if (veganFriendly) {
            
            for (auto res : restaurants) if (res[2]) res_vegenF.push_back(res);
        
        } else {

            for (auto res : restaurants) res_vegenF.push_back(res);
        }

        // 按 rating 和 id 排序
        sort(res_vegenF.begin(), res_vegenF.end(), [](const vector<int>& a, const vector<int>& b) {
                                                                                if (a[1] == b[1]) return a[0] > b[0];

                                                                                else return a[1] > b[1];
            
                                                                            }
        );

        for (auto res : res_vegenF) {
            if (res[3] <= maxPrice && res[4] <= maxDistance) ans.emplace_back(res[0]);
        }
        
        return ans;
    }
};
// @lc code=end

