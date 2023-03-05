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

// 第二次 AC
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        // 贪心 每次都上 4 个人

        int wait = 0; // 正在等待的人数

        int mon = 0, idx = 0; // 赚的钱 摩天轮旋转的次数

        int res = -1;

        // 最后等待的乘客数量为 0 
        for (auto n : customers) {
            idx ++;

            if (n != 0) {
                wait = n;

                break;
            }
        }

        int cus = 0; // 摩天轮里总的乘客数量

        while (wait || idx < customers.size()) {

            if (wait > 4) cus += 4, wait -= 4;

            else cus += wait, wait -= wait;

            int po = cus * boardingCost - idx * runningCost;

            if (po > mon) res = idx, mon = po;

            //cout << po << ' ' << mon << ' ' << idx << endl;

            if (idx < customers.size()) wait += customers[idx];

            idx ++; // 摩天轮转一次

        }

        /*for (auto n : customers) {
            wait += n; // 还未启动时等待的人数

            int cus = 0; // 每次的乘客数量

            if (wait > 4) cus = 4 ,wait -= 4;

            else cus = wait, wait -= wait;

            mon += cus * boardingCost - runningCost;

            
        }*/

        return res;

    }
};
// @lc code=end

