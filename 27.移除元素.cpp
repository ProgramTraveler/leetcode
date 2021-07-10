/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //双指针
        int slow=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                //如果快的不低于val，就把值存入慢指针的位置
                nums[slow]=nums[i];
                slow++;
            }
        }
        return slow;
        
    }
};
// @lc code=end

