/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

// @lc code=start
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) { // 题意是真难读
        // 优先队列很少用 这次刚好熟悉一下

        const int mod = 1e9 + 7;

        // 分别按最大和最小排列的优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;

        for (auto && order : orders) { // 对二维数组的一种新的遍历方式 (对我而言)
            int price = order[0], amount = order[1], orderType = order[2];

            if (orderType == 0) { // 如果是采购订单
                while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price) { // 满足采购的条件
                    auto sellOrder = sellOrders.top(); // 当前满足条件的订单

                    sellOrders.pop();

                    int sellAmount = min(amount, sellOrder.second); // 需要消耗的最小订单数量

                    amount -= sellAmount; 

                    sellOrder.second -= sellAmount;

                    if (sellOrder.second > 0) sellOrders.push(sellOrder);    
                } 

                if (amount > 0) buyOrders.emplace(price, amount); // 如果当前采购并没有完成 继续采购
                
            } else {
                    while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
                        auto buyOrder = buyOrders.top();

                        buyOrders.pop();

                        int buyAmount = min(amount, buyOrder.second);

                        amount -= buyAmount;

                        buyOrder.second -= buyAmount;

                        if (buyOrder.second > 0) buyOrders.push(buyOrder);
                    }

                    if (amount > 0) sellOrders.emplace(price, amount);
                }
        }

        int res = 0;

        while (!buyOrders.empty()) {
            res = (res + buyOrders.top().second) % mod;

            buyOrders.pop();
        }

        while (!sellOrders.empty()) {
            res = (res + sellOrders.top().second) % mod;

            sellOrders.pop();
        }
       
        return res;
    }
};
// @lc code=end

