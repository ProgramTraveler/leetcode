/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
        */

        int first=0;
        int last=nums.size()-1;

        while (first<=last) {
            int mid = first+(last-first)/2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    last= mid - 1;
                } else {
                    first= mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                    first = mid + 1;
                } else {
                    last= mid - 1;
                }
            }
        }
        return -1;

    
    }
};
// @lc code=end

