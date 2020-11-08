/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
       int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0;
        int maxProfit = 0;
        int ans = -1;
        int waitCnt = 0;
        
        int turn = 0;
        while (waitCnt != 0 || turn < customers.size()) {
            waitCnt += (turn < customers.size()) ? customers[turn] : 0;
            int upCnt = min(waitCnt, 4);
            waitCnt -= upCnt;
            profit += upCnt * boardingCost - runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                ans = turn + 1;
            }
            turn++;
        }
        
        return ans;
    }

};
// @lc code=end

