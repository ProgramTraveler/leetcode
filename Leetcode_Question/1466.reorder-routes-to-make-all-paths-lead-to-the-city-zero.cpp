/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 * @lcpr version=30112
 *
 * [1466] 重新规划路线
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
class Solution
{
public:
    int dfs(int x, int parent, vector<vector<pair<int, int>>> &e)
    {
        int res = 0;

        for (auto &edge : e[x])
        {
            if (edge.first == parent)
                continue; // 防止环

            res += edge.second + dfs(edge.first, x, e);
        }

        return res;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {

        //* 题目保证两个城市之间只有 唯一 一条路径可选择
        std::vector<vector<pair<int, int>>> e(n); // 起点对应的终点，以及是否反向

        for (const auto &edge : connections)
        {
            e[edge[0]].emplace_back(std::make_pair(edge[1], 1));
            e[edge[1]].emplace_back(std::make_pair(edge[0], 0)); // 反向
        }

        return dfs(0, -1, e);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,0],[1,2],[3,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0],[2,0]]\n
// @lcpr case=end

 */
