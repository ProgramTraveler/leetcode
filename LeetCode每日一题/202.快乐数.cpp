/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int gitNum(int num) //求每次数的平方和
    {
        int sum=0;
        while(num>0)
        {
            int tem=num%10;
            sum+=tem*tem;
            num=num/10;
        }
        return sum;
    }
    bool isHappy(int n) 
    {
        int fast=gitNum(n); //快指针在起点向后移动两位
        fast=gitNum(fast);
        int slow=gitNum(n);//慢指针在起点后移动一位
        //通过循环判断两数相等后退出，因为是个是个循环过程，快指针一定会追上慢指针
        while(fast!=slow)
        {
            slow=gitNum(slow);
            fast=gitNum(fast);
            fast=gitNum(fast);
        }
        return fast==1 ? true:false;
    }
};
// @lc code=end

