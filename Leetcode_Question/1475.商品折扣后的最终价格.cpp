/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        bool index = false; //该标志位表示是否得到折扣

        for (int i = 0; i < prices.size() - 1; i ++) {
            int flag = i + 1;
            while (flag < prices.size()) {
                index = false;

                if (prices[i] >= prices[flag]) {
                    ans.push_back(prices[i] - prices[flag]);
                    index = true;
                    break;
                }
                flag ++;
            }
            
            if (!index) ans.push_back(prices[i]);
        }

        ans.push_back(prices[prices.size() - 1]); //最后一个是不会有折扣的,直接放入最终的结果

        return ans;
    }
};
// @lc code=end

