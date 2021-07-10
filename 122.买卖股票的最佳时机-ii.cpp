/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int money=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            money=money+max(0,prices[i+1]-prices[i]); //每次的收益就是有钱可赚的时候，（画出折线图就是曲线上升的波段）
        }
        
        return money;    
    }
};
// @lc code=end

