/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            int index = 0;
            while(index < m && nums1[i] != nums2[index]) index ++; //定位nums1中数字出现的位置
            while (index < m && nums1[i] >= nums2[index]) index ++; //从当前位置开始向右边查找

            index < m ? res.push_back(nums2[index]) : res.push_back(-1); //根据下标是否越界来判断是否有目标数字
        }
        return res;
    }
};
// @lc code=end

