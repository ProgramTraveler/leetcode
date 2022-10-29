/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int fun(string x) {
        if (x == "type") return 0;

        if (x == "color") return 1;

        if (x == "name") return 2;

        return -1;
    }

    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = fun(ruleKey), res = 0;

        for (int i = 0; i < items.size(); i ++) {
            if (items[i][idx] == ruleValue) res ++;
        }
        return res;
    }
};
// @lc code=end

