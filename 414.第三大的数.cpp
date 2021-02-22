/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        set<int> s(nums.begin(), nums.end());
        auto it = s.end();
        it--;
        if(s.size() >= 3){
            it--;
            it--;
        }
        return *it;
    }
};

// @lc code=end

