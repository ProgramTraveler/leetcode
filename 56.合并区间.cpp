/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end()); //对数组进行排序，这样可合并的一定是连续的
        vector<vector<int>> answer; //记录最后的答案
    
        for(int i=0;i<intervals.size();)
        {
            int tem=intervals[i][1]; //设置一个tem来记录临时的最大值
            int j=i+1; //去到下一行来是否可以合并
            while(j<intervals.size() && intervals[j][0]<=tem) //可以合并的条件
            {
                //找到可以合并的情况下，tem的最大值
                tem=max(tem,intervals[j][1]);
                //往下一行寻找
                j++;
            }
            //保存合并后的区间
            answer.push_back({intervals[i][0],tem});
            i=j; //跳过已经合并过的区域
        }
        return answer;
    }
};
// @lc code=end

