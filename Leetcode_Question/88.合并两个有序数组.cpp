/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void quick_sort(vector<int>& nums1, int l, int r) { //快速排序
        if (l >= r) return ; //递归结束条件
        int x = nums1[l + r >> 1]; 
        int i = l - 1;
        int j = r + 1;
        while (i < j) {
            do i ++; while (x > nums1[i]); //调整这两个判断条件可以来控制逆序和顺序
            do j --; while (x < nums1[j]);
            if (i < j) swap(nums1[i], nums1[j]);
        }
        quick_sort(nums1, l, j);
        quick_sort(nums1, j + 1 , r);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i ++) { //将数组合二为一
            nums1[m ++] = nums2[i];
        }
        quick_sort(nums1, 0, nums1.size() - 1); //对合并的数组进行排序
    }
};
// @lc code=end

