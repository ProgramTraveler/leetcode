/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 * @lcpr version=30113
 *
 * [2744] 最大字符串配对数目
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
    int maximumNumberOfStringPairs(vector<string>& words) {
      // has 碰撞
      std::unordered_map<long long, int> num_cnt;

      int res = 0;
      int HASH1 = 1882;
      int HASH2 = 83;

      for (const auto& s : words) {
        int n1 = s.front() - 'a' + 1;
        int n2 = s.back() - 'a' + 1;

        long long idx = n1 * HASH1 * n2  * HASH2 - n1 - n2;

        if ((++ num_cnt[idx]) >= 2) res ++;
      }

      return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cd","ac","dc","ca","zz"]\n
// @lcpr case=end

// @lcpr case=start
// ["ab","ba","cc"]\n
// @lcpr case=end

// @lcpr case=start
// ["aa","ab"]\n
// @lcpr case=end

 */

