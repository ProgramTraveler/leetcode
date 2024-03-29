/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 * @lcpr version=30117
 *
 * [2908] 元素和最小的山形三元组 I
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
    int minimumSum(vector<int>& nums) {
        int res = 200;
        for (int i = 0; i < nums.size(); i ++) {
            // 双指针
            // 跳过开始点和最后一个点
            int l = i - 1, r = i + 1;
            int min_l = INT_MAX, min_r = INT_MAX;
            bool is_succ_find_l = false; // 成功找到左半点
            bool is_succ_find_r = false; // 成功找到右半点
            while (l >= 0) {
                if (nums[l] < nums[i]) {
                    min_l = std::min(min_l, nums[l]);
                    is_succ_find_l = true;
                }
                l --;
            }
            while (r < nums.size()) {
                if (nums[r] < nums[i]) {
                    min_r = std::min(min_r, nums[r]);
                    is_succ_find_r = true;
                }
                r ++;
            }
            if (is_succ_find_l && is_succ_find_r) {
                res = std::min(res, nums[i] + min_l + min_r);
            }
        }

        return res < 200 ? res : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */

