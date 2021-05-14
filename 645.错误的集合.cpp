/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> n(nums.size(),0);
        vector<int> res(2,0);
        for(int i = 0; i < nums.size(); i ++) {
            n[nums[i] - 1] ++;
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(n[i] == 2) res[0] = i + 1;
            else if(n[i] == 0) res[1] = i + 1;
        }
        return res;
    }
};
// @lc code=end

