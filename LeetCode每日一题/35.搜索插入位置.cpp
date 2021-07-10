/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first=0; //左边的下标
        int last=nums.size()-1; //右边的下标
        //这里循环结束的条件很重要
        while(first<=last){
            //计算mid的值（这里这样写是个人习惯）
            int mid=first+(last-first)/2;
            //相等就直接返回
            if(nums[mid]==target) {
                return mid;
            } //如果比target大，就last--，否则first++
            else if(nums[mid]>target){
                last--;
            }else {
                first++;
            }
        }
        //如果没有相等的机返回first
        return first;
    }
};
// @lc code=end

