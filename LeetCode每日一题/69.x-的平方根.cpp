/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x)
     {
         if(x==0)
         {
             return 0;
         }
         int left=1;
         int right=x/2;
         while(left<right)
         {
             //注意这一行为关键代码
             int mid=((left+right)/2)+1;
             if(mid>x/mid)
             {
                right=mid-1;
             }
             else
             {
                 left=mid;
             }
         }
         return left;
    }
};
// @lc code=end

