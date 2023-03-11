/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<int>& nums,vector<vector<int>>& answer,vector<int>& tem_ans,int index)
    {
        if(index==nums.size())  //结束的条件
        {
            answer.push_back(tem_ans); //把临时的答案传入临时答案
            return;
        }
        //把选择的数传入临时数组
        tem_ans.push_back(nums[index]);
        DFS(nums,answer,tem_ans,index+1);
        //不把当前的数放入数组
        tem_ans.pop_back();
        DFS(nums,answer,tem_ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> answer; //存储最终的答案
        vector<int> tem_ans; //记录临时答案
        DFS(nums,answer,tem_ans,0);
        return answer;    
    }
};
// @lc code=end

