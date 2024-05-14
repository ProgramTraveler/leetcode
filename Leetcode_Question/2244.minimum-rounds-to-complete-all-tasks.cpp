/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 * @lcpr version=30122
 *
 * [2244] 完成所有任务需要的最少轮数
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
    int minimumRounds(vector<int>& tasks) {
        int res = 0;

        std::unordered_map<int, int> cnt;
        for (int i = 0; i < static_cast<int>(tasks.size()); i ++) {
            cnt[tasks.at(i)] ++;
        }

        for (const auto& n : cnt) {
            if (n.second < 2) return -1;
            res += (n.second + 2) / 3;
        }
        
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3,2,4,4,4,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3]\n
// @lcpr case=end

 */

