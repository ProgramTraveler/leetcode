/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        
        //i代表行数和每行硬币数，n逐行减少i个，当i行大于n的时候代表剩余硬币数量无法在该行构成一行，此时i-1就是总行数。
        int i=0;
        for(i=1;i<=n;i++)
        {
            n-=i;
        }
        return i-1;
    }
};
// @lc code=end

