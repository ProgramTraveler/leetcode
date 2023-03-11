/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) 
    {
        //特殊情况，为空直接返回
        if(height.size()==0) return 0;

        int answer=0; //存储答案
        int start=0; //头指针
        int last=height.size()-1; //尾指针
        int MaxStart=height[start]; //初始化最左边的最大值
        int MaxLast=height[last]; //初始化最右边的最大值
        //由两头向中间寻找
        while(start<=last) 
        {
            MaxStart=max(MaxStart,height[start]); //记录过程中左边的最大值
            MaxLast=max(MaxLast,height[last]); //记录过程中右边的最大值
            if(MaxStart<MaxLast) //如果右边的值大于左边的（说明左边的比较低）
            {
                answer+=MaxStart-height[start]; //计算左边的高度差
                start++; 
            }
            else
            {
                answer+=MaxLast-height[last]; //反之说明右边的比较低，计算右边的高度差
                last--; 
            }
        }
        return answer;
    }
};
// @lc code=end

