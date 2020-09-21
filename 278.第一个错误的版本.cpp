/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int left=1;
        int right=n;
        while(left<right)
        {
            //关键在mid的求法，第二种写法容易溢出（测试用例中有一个1亿多个版本的（超过了int的上限就变成负数了），真是服了，产品经理不当人系列），所以按第一种方法写
            int mid=left+(right-left)/2;
            //int mid=(left+right)/2;
            if(isBadVersion(mid)==true)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
// @lc code=end

