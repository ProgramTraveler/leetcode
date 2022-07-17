/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) { //想到了会用双循环但是没有这么清晰
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i ++) { 
            int c = i, count = 0;

            while (nums[c] != -1) { //为了防止环的循环计算对探测过的环做-1标记（不做标记也是可以的但需要每次遍历到底暴力搜索）
                count ++;
                int temp = c;
                c = nums[c];
                nums[temp] = -1;
            }

            ans = max(ans, count);
        }
        
        return ans;
    }
};
// @lc code=end

