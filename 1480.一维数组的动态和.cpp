/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i ++) {
            //cout<<i<<" "<<res[i]<<endl;
            res[i] = res[i - 1] + nums[i]; 
        }
        return res;
    }
};
// @lc code=end

