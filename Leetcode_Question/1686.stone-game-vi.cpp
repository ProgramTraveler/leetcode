/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 * @lcpr version=30116
 *
 * [1686] 石子游戏 VI
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
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        // Alice 先手
        int n = a.size();
        std::vector<int> ids(n);

        std::iota(ids.begin(), ids.end(), 0);
        ranges::sort(ids, [&](int i, int j) {
            return a[i] + b[i] > a[j] + b[j];
        });

        int diff = 0;
        for (int i = 0; i < n; i ++) {
            diff += i % 2 == 0 ? a[ids[i]] : -b[ids[i]];
        }

        return (diff > 0) - (diff < 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[1,6,7]\n
// @lcpr case=end

 */

