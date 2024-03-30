/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 * @lcpr version=30121
 *
 * [2952] 需要添加的硬币的最小数量
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
    int minimumAddedCoins(vector<int>& coins, int target) {
        // 
        std::sort(coins.begin(), coins.end());
        int ans = 0, s = 1, i = 0;
        while (s <= target) {
            if (i < coins.size() && coins[i] <= s) {
                s += coins[i ++];
            } else {
                s *= 2;
                ans ++;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,10]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,5,7,19]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n20\n
// @lcpr case=end

 */

