/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            int left;
            i == nums.size() - 1 ? left = 0 : left = i + 1;
            int index = -1;
            while (left != i) {
                if (nums[left] > nums[i]) {
                    index = nums[left];
                    break;
                }
                left == nums.size() - 1 ? left = 0 : left ++;
            }
            ans.push_back(index);
        }
        return ans;
    }
};
// @lc code=end

