/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<int>& candidates,int target,vector<vector<int>>& answer,vector<int>& tem,int  num)
    {
        if(target==0)
        {
            answer.push_back(tem);
            return;
        }
        if(target<0) return;

        for(int i=num;i<candidates.size();i++)
        {
            if(i>num && candidates[i]==candidates[i-1]) continue; //如果这个数字被使用过了，就直接跳过，因为它不能存在重复的组合（本来想在分支里把使用过数字删掉的）

            //如果没被使用，就进行检查
            else
            {
                tem.push_back(candidates[i]);
                DFS(candidates,target-candidates[i],answer,tem,i+1); //在往下走，去进行后面数字的检查
                tem.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
         sort(candidates.begin(), candidates.end()); //对题目所给的数列进行排序，不然达不到AC的要求
         vector<vector<int>> answer; //记录最终的答案
         vector<int> tem; //记录每个分支的临时答案
         DFS(candidates,target,answer,tem,0);
         return answer;  
    }
};
// @lc code=end

