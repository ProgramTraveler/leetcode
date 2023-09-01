/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // cost1 钢笔的价格 cost2 铅笔的价格
        // 注意数据类型为 long long
        long long res = 0;

        if (total < cost1 && total < cost2) return 1;

        long long cnt1 = 0, cnt2 = 0; // 购买钢笔和铅笔的数量

        while ((total - cost1 * cnt1) >= 0) { // 购买钢笔后剩余的钱为正
            cnt2 = (total - cost1 * cnt1) / cost2 + 1; // +1 是把 0 的情况考虑上

            res += cnt2;

            cnt1 ++;
        }

        return res;
    }
};
// @lc code=end

