/*
 * @lc app=leetcode.cn id=3038 lang=cpp
 *
 * [3038] 相同分数的最大操作数目 I
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int res = 0;
        int l = 0, r = l + 1;
        int n = static_cast<int>(nums.size());
        if (r >= n) {
          return 0;
        }

        int sum = nums.at(l) + nums.at(r);
        while (r < n) {
          if (nums.at(l) + nums.at(r) == sum) {
            res ++;
            l += 2;
            r = l + 1;
          } else {
            break;
          }
        }

        return res;
    }
};
// @lc code=end

