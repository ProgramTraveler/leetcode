/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 * @lcpr version=30113
 *
 * [2861] 最大合金数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l = 1, r = 2e8;
        int res = 0;

        while (l <= r) {
          int mid = l + (r - l) / 2;
          bool valid = false;

          for (int i = 0; i < k; i ++) {
            long long spend = 0;
            for (int j = 0; j < n; j ++) {
              spend += std::fmax(static_cast<long long>(composition[i][j]) * mid - stock[j], 0LL) * cost[j];
            }

            if (spend <= budget) {
              valid = true;
              break;
            }
          }
          if (valid) {
            res = mid;
            l = mid + 1;
          } else r = mid - 1;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,100]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n10\n[[2,1],[1,2],[1,1]]\n[1,1]\n[5,5]\n
// @lcpr case=end

 */

