/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/*
    这段超时，但是以前是可以AC的
*/
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max_prices = 0;
        for (int i = 0; i < prices.size(); i ++) {
            int start = i + 1;
            int end = prices.size();
            //if(i>0 && prices[i]>prices[i-1]) continue;
            while (start < end) {
                if(prices[i] < prices[start]) {
                    Max_prices=max(Max_prices, prices[start] - prices[i]);
                    //cout<<Max_prices;
                    start++;
                }
                else {
                    start ++;
                }
            }
        }
        return Max_prices;
    }
};*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = int(1e9);
        int maxprofit = 0;
        for (auto price : prices){
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};
// @lc code=end

