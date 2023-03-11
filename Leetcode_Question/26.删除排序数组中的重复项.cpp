/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        sort(nums.begin(),nums.end()); //把所给题解的数组排序
        //从头开始遍历，寻找相同的数字
        for(int i=0;i<nums.size();i++)
        {
            //如果在这个位置找到了前一个是重复数字，就把这个数字删掉
            if(i>0 && nums[i]==nums[i-1])
            {
                //如果遇到和之前的数一样的情况就执行修改
                //定义首指针
                int start=i;
                //定义尾指针
                int last=nums.size()-1;
                //把重复的位置删掉（就是后面的把这个数字给覆盖掉）
                while(start<last)
                {
                    nums[start]=nums[start+1];
                    start++;
                }
                nums.pop_back(); //取出最后的那个数字（因为它已经移到了前一个数字）
                //在重新调整的数组的那个数字开始遍历
                i--;
            }
            else continue;
        }
        //返回最后的数组长度
        return nums.size();
    }
};
// @lc code=end

