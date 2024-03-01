/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 * @lcpr version=30116
 *
 * [2369] 检查数组是否存在有效划分
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
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);

        f[0] = true;
        for (int i = 1; i < n; i ++) {
            if (f[i - 1] && nums[i] == nums[i - 1] || 
            i > 1 && f[i - 2] && (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] ||
            nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)) {
                f[i + 1] = true;
            }
        }

        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,4,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2]\n
// @lcpr case=end

 */

