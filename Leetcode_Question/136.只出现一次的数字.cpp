/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
//这个用位运算的太妙了，简单而且省事 
class Solution {
public:
    int singleNumber(vector<int>& nums)
     {
        int result = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            result = result^nums[i]; //异或运算（A^A=0,A^A^B=B）
        }
        return result;
    }
};


//这个方法比较暴力，就是挨个比较，太low了，虽然可以解决，但超出了时间限制
/*class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j] && i!=j)
                {
                    //cout<<nums[i]<<" "<<nums[j]<<endl;
                    break;
                }
                else if(nums[i]!=nums[j] && j<nums.size()-1)
                {
                    continue;
                }
                else if(j==nums.size()-1)
                {
                    //cout<<"n:"<<nums[i]<<endl;
                    n= nums[i];
                }
            }
        }
        return n;
    }
};*/
// @lc code=end

