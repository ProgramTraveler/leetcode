/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 * @lcpr version=30113
 *
 * [2765] 最长交替子序列
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
    int alternatingSubarray(vector<int> &nums) {
        int ans = -1;
        int i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] != 1) {
                i++; // 直接跳过
                continue;
            }
            int i0 = i; // 记录这一组的开始位置
            i += 2; // i 和 i+1 已经满足要求，从 i+2 开始判断
            while (i < n && nums[i] == nums[i - 2]) {
                i++;
            }
            // 从 i0 到 i-1 是满足题目要求的（并且无法再延长的）子数组
            ans = max(ans, i - i0);
            i--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,4,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6]\n
// @lcpr case=end

 */

