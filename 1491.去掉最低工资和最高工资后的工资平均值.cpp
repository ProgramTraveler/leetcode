/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end()); //对数组进行排序
        salary.pop_back(); //取出最大的值
        reverse(salary.begin(),salary.end());//在对数组进行反序
        salary.pop_back(); //取出最小的那个值
        double sum=0; //工资和
        for(int i=0.0;i<salary.size();i++){
            sum+=salary[i]; //将取出最大值和最小值后的值加起来
        }
        return sum/salary.size();
    }
};
// @lc code=end

