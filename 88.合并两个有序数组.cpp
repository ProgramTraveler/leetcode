/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void quick_sort(vector<int>& nums1, int l, int r) {
        if (l >= r) return ;

        int x = nums1[l + r >> 1];

        int i = l - 1;

        int j = r + 1;
        
        while (i < j) {
            do i ++; while (nums1[i] < x);
            do j --; while (nums1[j] > x);
            if (i < j) swap(nums1[i], nums1[j]);
        }
        quick_sort(nums1, l, j);
        quick_sort(nums1, j + 1, r);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i ++) {
            nums1[m ++] = nums2[i];
        }
        quick_sort(nums1, 0, nums1.size() - 1);
    }
};
// @lc code=end

