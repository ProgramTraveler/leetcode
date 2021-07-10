/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans; //保存最终的结果
        int n = nums.size(); //数组的长度
        //对数组进行处理，如果遍历到当前的某个数，那么就这个数位置的数增加n
        for (int i = 0; i < nums.size(); i ++) {
            int x = (nums[i] - 1) % n;
            nums[x] += n;
        }
        //对原数组进行遍历，如果有数比n小，说明该位置是缺失的数
        for (int i =0; i < nums.size(); i ++) {
            if (nums[i] <= n) 
                ans.push_back(i + 1);
            
        }
        //返回最后的结果
        return ans;
    }
};
// @lc code=end

