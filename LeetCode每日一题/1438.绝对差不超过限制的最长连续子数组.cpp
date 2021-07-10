/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int res = INT_MIN;
        int left = 0, right = 0;
        while (right < nums.size()) {
            st.insert(nums[right]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[left]));
                left ++;
            }
            res = max(res, right - left + 1);
            right ++;
        }
        return res;
    }
};
// @lc code=end

