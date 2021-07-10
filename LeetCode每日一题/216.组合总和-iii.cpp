/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<vector<int>>& answer,vector<int>& tem,vector<int>& Num,int k,int n,int count,int num) 
    {
        if(n==0 && count==k) //传入结果的条件（count记录在tem中的个数，用来筛选满足结果的答案）
        {
            answer.push_back(tem);
            return;
        }
        if(n<0) return; //不满足的条件
        //这就和组合总和1的一样，就多个count的记录
        while(num<Num.size())
        {
            tem.push_back(Num[num]); //传入数字
            //count++;
            //cout<<count<<endl;
            DFS(answer,tem,Num,k,n-Num[num],count+1,num+1); //继续下面的分支，count加一（因为满足条件，去找下一个元素）
            tem.pop_back(); //如果不满足就弹出这个数字
            num++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> answer; //记录最终的答案
        vector<int> tem; //记录每次分支下的结果
        vector<int> Num={1,2,3,4,5,6,7,8,9}; //构建出一个由1到9的数组
        DFS(answer,tem,Num,k,n,0,0);
        return answer;
    }
};
// @lc code=end

