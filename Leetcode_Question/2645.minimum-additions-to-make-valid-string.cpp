/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 * @lcpr version=30113
 *
 * [2645] 构造有效字符串的最少插入数
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
    int addMinimum(string word) {
      int t = 1;

      for (int i = 1; i < word.size(); i ++) {
        t += word[i - 1] >= word[i];
      }

      return t * 3 - word.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "b"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

