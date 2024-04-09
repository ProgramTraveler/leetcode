/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=30121
 *
 * [2529] 正整数和负整数的最大计数
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
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > 0) break;
            if (nums[i] < 0) cnt1 ++;
            if (nums[i] == 0) cnt2 ++;
        }
        return std::fmax(cnt1, n - cnt1 - cnt2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */

