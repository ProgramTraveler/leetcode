/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return ;
        int x = nums[l + r >>1], i = l - 1, j = r + 1;
        while (i < j) {
            do i ++; while (nums[i] < x);
            do j --; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    int majorityElement(vector<int>& nums) {
        //hash表的做法太慢了，看了一下题解，发现有更好的方法
        /*unordered_map<int, int>M;
        for (int i = 0; i < nums.size(); i ++)
            M[nums[i]] ++;
        for (auto &s : M)
            if (s.second > nums.size() >> 1)
                return s.first;
        return 0;*/
        
        //使用一下排序，顺便练习一下手写快排，当然你也可以直接使用sort()排序
        quick_sort(nums, 0, nums.size() - 1);
        return nums[nums.size() >> 1];
    }
};
// @lc code=end

