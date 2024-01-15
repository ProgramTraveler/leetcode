/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 * @lcpr version=30113
 *
 * [2696] 删除子串后的字符串最小长度
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
    int minLength(string s) {
      // 由大写字母构成
      std::stack<char> st;

      for (const auto& c :s) {
        bool sig1_pop_stack = (c == 'B') && !st.empty() && st.top() == 'A'; // 出栈条件1
        bool sig2_pop_stack = (c == 'D') && !st.empty() && st.top() == 'C'; // 出栈条件2

        if (sig1_pop_stack || sig2_pop_stack) {
          st.pop();
          continue;
        }

        // 入栈
        st.push(c);
      }

      return st.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ABFCACDB"\n
// @lcpr case=end

// @lcpr case=start
// "ACBBD"\n
// @lcpr case=end

 */

