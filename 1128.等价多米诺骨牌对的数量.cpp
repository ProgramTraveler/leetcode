/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> ans(100); //记录生成的100以内的数字
        int count = 0; //记录多米诺骨牌的配对数量
        //对数组进行遍历，并记录配对的数量
        for (int i = 0; i < dominoes.size(); i ++) {
            int idex = dominoes[i][0] < dominoes[i][1] ? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
            count += ans[idex];
            ans[idex] ++;
        }
        return count;
    } 
};
// @lc code=end

