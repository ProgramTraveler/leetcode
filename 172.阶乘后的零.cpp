/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) 
    {
        //思路就是找出因子中含5的数字的个数（如10的阶乘里，10的因子有5,5的的因子是5，两个5说明有两个0）
       int count=0;
       while(n>=5)
       {
           count+=n/5;
           n=n/5;
           
       }
       return count;
        

    }
};
// @lc code=end

