/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1); //记录最终的结果
        //第一个循环用来更新行数
        for (int i = 2; i <= rowIndex; i ++)
            //第二个循环用来更新新一行的数据 
            for (int j = i -1; j >= 1; j --) 
                res[j] += res[j - 1];
        //返回最终的结果
        return res;
    }
};
// @lc code=end

