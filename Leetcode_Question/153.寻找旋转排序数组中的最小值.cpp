/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2; //获得中间的值

            if (nums[mid] < nums[right]) //如果当前的值比最右边的值小的话，说明最小的值在左边的区域
                right = mid;

            else //否则最小值就在右边的区域
                left = mid + 1;
        }
        return nums[left]; //当左右指针相邻时，最小的就是左边的
    }
};
// @lc code=end

