/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 * @lcpr version=30112
 *
 * [2697] 字典序最小回文串
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
class Solution
{
public:
  string makeSmallestPalindrome(string s)
  {
    // 无脑双指针
    int l = 0, r = s.size() - 1;

    while (l <= r)
    {
      if (s[l] != s[r])
      { // 如果二者不相同，按照题目要求 字典序最小
        int min_int = std::fmin(s[l] - 'a', s[r] - 'a');
        char min_c = min_int + 'a';

        s[l] = min_c;
        s[r] = min_c;
      }

      l++;
      r--;
    }

    return s;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "egcfe"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

// @lcpr case=start
// "seven"\n
// @lcpr case=end

 */
