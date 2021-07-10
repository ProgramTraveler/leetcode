/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> answer;
    void seek(int target,vector<int> candidates,vector<int> &temporary,int num)
    {
        if(target==0) 
        {
            answer.push_back(temporary);
            return;
        }
        if(target<0) return;
        while(num<candidates.size())
        {
            temporary.push_back(candidates[num]);
            seek(target-candidates[num],candidates,temporary,num);
            temporary.pop_back();
            num++;
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
     {
        vector<int> temporary;
        seek(target,candidates,temporary,0);
        return answer;
         
    }
};
// @lc code=end

