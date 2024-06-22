/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 *
 * [2748] 美丽下标对的数目
 */

// @lc code=start
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
      int res = 0;
      int cnt[10]{};

      for (int x : nums) {
        for (int y = 1; y < 10; y ++) {
          if (cnt[y] && gcd(y, x % 10) == 1) {
            res += cnt[y];
          }
        }

        while (x >= 10) {
          x /= 10;
        }

        cnt[x] ++;
      }

      return res;
    }
};
// @lc code=end

