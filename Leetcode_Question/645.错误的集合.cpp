/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> tempSt(nums.size(), 0); //记录数字出现的次数
        vector<int> res(2, 0); //返回最终的结果
        for (int i = 0; i < nums.size(); i ++) {
            tempSt[nums[i] - 1] ++;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (tempSt[i] == 2) res[0] = i + 1;
            if (tempSt[i] == 0) res[1] = i + 1;
        }
        return res;
    }
};
// @lc code=end

