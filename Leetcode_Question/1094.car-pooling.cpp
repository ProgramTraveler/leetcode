/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30111
 *
 * [1094] 拼车
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 差分数组
        map<int, int> d;
        for (auto& t : trips) {
            int num = t[0], from = t[1], to = t[2];

            d[from] += num;
            d[to] -= num;
        }

        int s = 0;
        for (auto& [_, v] : d) {
            s += v;
            if (s > capacity) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

