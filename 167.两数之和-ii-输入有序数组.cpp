/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] > target)
                right --;
            else if (numbers[left] + numbers[right] < target) 
                left ++;
            else {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

