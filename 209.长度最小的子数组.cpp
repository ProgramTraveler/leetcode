/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        //这是考虑tem>=s的情况，通过对flag的移动（如果tem>s的话就移动flag，相当于减去小的数字）
        int tem=0;
        int len=1e7;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            tem+=nums[i];
            while(tem>=s)
            {
                len=min(len,i-flag+1);
                tem-=nums[flag++];
            }
        }
        return flag==0 ? 0:len;
        
        //这是自己的想法写的（和上面思想的差别就是while判断里，我是tem<s考虑的，这就导致要有特殊情况的考虑（如[1,1] 3 这个例子）），最后强行AC，实在是太耗运行时间了。
        /*if(nums.size()==0) return nums.size();

        int len=1e7;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum<s) return 0;

        for(int i=0;i<nums.size();i++)
        {
            int start=i+1;
            int end=nums.size();
            int tem=nums[i];
            int tem_len=1; 
            while(tem<s && start<end)
            {
                tem+=nums[start];
                tem_len++;
                start++;
            }
            if(tem>=s) len=min(len,tem_len);

        }
       return len;*/
    }
};
// @lc code=end

