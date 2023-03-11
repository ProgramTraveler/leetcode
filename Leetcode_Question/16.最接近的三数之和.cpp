/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int sum=1e7; //记录最优的三数之和

        sort(nums.begin(),nums.end()); //将数组中的数排序

        for(int i=0;i<nums.size();i++)
        {
            //把重复的去掉(其实不去也可以，就是消耗和用时多一点)
            if(i>0 && nums[i]==nums[i-1]) continue;
            //定义头指针和尾指针
            int start=i+1;
            int last=nums.size()-1;

            while(start<last)
            {
                //存储临时的三数之和
                int tem_sum=nums[i]+nums[start]+nums[last];
                //如果和刚好和目标值一致，就直接返回
                if(tem_sum==target) return target;
                //比较临时的值和最优值哪个更接近目标值
                if (abs(tem_sum - target) < abs(sum - target)) sum = tem_sum;
                //如果当前值比目标值小，头指针移动（因为已经排好序了，所以下一个一定比当前的大）
                if (tem_sum < target)
                    start++;
                //如果大的话就移动尾指针
                else
                    last--;
                
            }
        }
        return sum;
    }
};
// @lc code=end

