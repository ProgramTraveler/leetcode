/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) 
    {
        if(n <= 3) return n - 1;  //必须切一刀
        //2和3不能再分了  分了就变小了 且3优于2
        int a = n / 3;
        int b = n % 3;
        if(b == 0)
        {
            //全部分成3
            return pow(3, a);
        }
        if(b == 1){
            //4   1 和 3 要变成2 * 2
            return pow(3, a-1) *4 ;
        }
        //b == 2  2不能再分了
        return pow(3, a) * 2;
    }
};
// @lc code=end

