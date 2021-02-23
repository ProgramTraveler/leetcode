/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    //快排模板没得说
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return ;
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i ++; while (nums[i] < x);
            do j --; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

