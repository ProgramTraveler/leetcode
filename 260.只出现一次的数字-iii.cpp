/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    //芜湖，直接上map刷一波，就是没达到要求，击败有点可怜
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i ++) 
            mp[nums[i]] ++;
        
        for (auto i : mp) { //这个竟然写对了，这种结构还是第一次写
            if (i.second == 1)
             res.push_back(i.first);
        }
        return res;
    }
};
// @lc code=end

