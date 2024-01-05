/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 * @lcpr version=30112
 *
 * [2735] 收集巧克力
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
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();

        std::vector<long long> s(n);

        for (int i = 0; i < n; i ++) s[i] = (long long) i * x;

        for (int i = 0; i < n; i ++) { // 子数组左端点
          int mn = nums[i];

          for (int j = i; j < n + i; j ++) { // 子数组右端点
            mn = std::fmin(mn, nums[j % n]); // 维护从 nums[i] 到 nums[j] 的最小值
            s[j - i] += mn; // 累加操作 j-i 次的花费
          }
        }

        return *min_element(s.begin(), s.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [20,1,15]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

 */

