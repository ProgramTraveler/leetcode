/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 * @lcpr version=30112
 *
 * [2048] 下一个更大的数值平衡数
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
  bool isBalance(int x)
  {
    vector<int> count(10);
    while (x > 0)
    {
      count[x % 10]++;
      x /= 10;
    }
    for (int d = 0; d < 10; ++d)
    {
      if (count[d] > 0 && count[d] != d)
      {
        return false;
      }
    }
    return true;
  }

  int nextBeautifulNumber(int n)
  {
    for (int i = n + 1; i <= 1224444; ++i)
    {
      if (isBalance(i))
      {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 1000\n
// @lcpr case=end

// @lcpr case=start
// 3000\n
// @lcpr case=end

 */
