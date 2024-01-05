/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 * @lcpr version=30112
 *
 * [2660] 保龄球游戏的获胜者
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
    int score(const vector<int> &player) {
        int res = 0;
        for (int i = 0; i < player.size(); i++) {
            if ((i > 0 && player[i - 1] == 10) || (i > 1 && player[i - 2] >= 10)) {
                res += 2 * player[i];
            } else {
                res += player[i];
            }
        }
        return res;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = score(player1);
        int s2 = score(player2);
        return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,10,7,9]\n[6,5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,7,6]\n[8,10,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n[4,1]\n
// @lcpr case=end

 */

