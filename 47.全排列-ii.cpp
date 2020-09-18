/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,vector<bool>& use)
    {
        if(nums.size()==temp.size()) //如果临时数组中的个数和原数组一样，说明已经找到了一组
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1] && use[i-1]==true) continue;

            if(use[i]==false)
            {
                use[i]=true;
                temp.push_back(nums[i]);
                DFS(nums,ans,temp,use);
                temp.pop_back();
                use[i]=false;
            }
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); //先对数组进行排序，方便后面的操作把重复的数字过滤掉
        vector<vector<int>> ans; //记录最终的答案
        vector<int> temp; //记录每个分支的结果
        vector<bool> use(nums.size(),false); //标记数组中的数字是否被使用过
        DFS(nums,ans,temp,use);

        return ans;
    }
};
// @lc code=end

