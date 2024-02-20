/*
 * @lc app=leetcode.cn id=LCP 30 lang=cpp
 * @lcpr version=30116
 *
 * [LCP 30] 魔塔游戏
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
    int magicTower(vector<int>& nums) {
        int res = 0; // 累计交换次数
        long long head = 0; // 累计正数
        long long tail = 0; // 累计负数

        std::priority_queue<int, vector<int>, greater<int>> q; // 最小堆

        for (const auto& n : nums) {
            if (n < 0) {
                q.push(n);
            }

            head += n;

            if (head < 0) { // 需要进行调整
                res ++;
                head -= q.top();
                tail += q.top();
                q.pop();
            }
        }

        head += tail;
        return head >= 0 ? res : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,100,100,-250,-60,-140,-50,-50,100,150]`>\n
// @lcpr case=end

// @lcpr case=start
// [-200,-300,400,0]`>\n
// @lcpr case=end

 */

