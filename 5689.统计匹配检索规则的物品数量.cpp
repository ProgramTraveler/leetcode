/*
 * @lc app=leetcode.cn id=5689 lang=cpp
 *
 * [5689] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        int index = 0;
        if (ruleKey == "type") index = 0;
        if (ruleKey == "color") index = 1;
        if (ruleKey == "name") index = 2;
        
        for (int i = 0; i < items.size(); i ++) {
            if (items[i][index] == ruleValue) ans ++;
            else continue;
        }
        return ans;
    }
};
// @lc code=end

