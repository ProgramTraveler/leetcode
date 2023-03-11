/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i = 0;i < nums.size();i ++) m[nums[i]] = i;
        //cout<<m.find(7)<<" "<<m.end()<<endl;
        for(int i = 0; i < nums.size(); i ++){
            if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i) {
                return{ i, m[target-nums[i]] };
            }
        }
        return {0,0};
        
        //之前使用的暴力求解，在第二次遇到后看见题解里有hash表的 
         /*
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
                else
                {
                    continue;
                }
            }
        }
    return {0,0};*/
    }
};
// @lc code=end

