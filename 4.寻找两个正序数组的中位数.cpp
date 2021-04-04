/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int left = 0, right = 0;
        while (left < nums1.size() && right < nums2.size()) {
            if (nums1[left] > nums2[right]) {
                ans.push_back(nums2[right]);
                right ++;
            }else {
                ans.push_back(nums1[left]);
                left ++;
            }
        }
        for (int i = left; i < nums1.size(); i ++)
            ans.push_back(nums1[i]);
        for (int i = right; i < nums2.size(); i ++)
            ans.push_back(nums2[i]);
        int index = ans.size();
        if (index % 2 == 0) 
            return (double)(ans[index >>1] + ans[(index >> 1) - 1]) / 2;
        else 
            return ans[index >> 1]; 
    }
};
// @lc code=end

