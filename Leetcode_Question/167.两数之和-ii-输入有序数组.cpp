/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] < target) {
                left ++;
            }else if (numbers[left] + numbers[right] > target) {
                right --;
            }else {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            }
        }
        return ans;

    }
};
// @lc code=end

