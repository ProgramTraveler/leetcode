/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    uint32_t lowbit(uint32_t x) {
        return x & (-x);
    }
    int hammingWeight(uint32_t n) {
        int res = 0; //记录出现1的个数
        while (n) { //如果当前值不为0，说明还有1
            n -= lowbit(n); //求第一个1出现的位置，并减去
            res ++; //进行了多少次减的操作，说明就有多少个1
        }
        //返回结果
        return res;
    }
};
// @lc code=end

