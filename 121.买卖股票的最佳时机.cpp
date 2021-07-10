/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int Max_prices=0; //记录数组中两个数的最大差值
        int Min_nums=1e7; //记录数组中的最小的数
        //一次遍历
        for(int i=0;i<prices.size();i++)
        {
            //记录扫描过程中股票的最低点
            Min_nums=min(Min_nums,prices[i]);
            //记录最低点与当前股票价钱的差值（保存最大差值）
            Max_prices=max(Max_prices,prices[i]-Min_nums);
        }
        return Max_prices;

        //下面这个算是个双指针吧，但感觉太费时间了，就写了个一次遍历的。
        /*int Max_prices=0;

        for(int i=0;i<prices.size();i++)
        {
            int start=i+1;
            int end=prices.size();

            if(i>0 && prices[i]>prices[i-1]) continue;

            while(start<end)
            {
                if(prices[i]<prices[start])
                {
                    Max_prices=max(Max_prices,prices[start]-prices[i]);
                    //cout<<Max_prices;
                    start++;
                }
                else
                {
                    start++;
                }
            }
        }
        return Max_prices;*/
    }
};
// @lc code=end

