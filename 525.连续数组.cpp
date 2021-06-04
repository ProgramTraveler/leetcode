/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int, int> m;
        int counter = 0;
        m[counter] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            int num = nums[i];
            if (num == 1) counter ++;
            else counter --;
            if (m.count(counter)) {
                int prevIndex = m[counter];
                maxLen = max(maxLen, i - prevIndex);
            }else m[counter] = i;
        }
        return maxLen;
    }
};
// @lc code=end

