/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 * @lcpr version=30112
 *
 * [2477] 到达首都的最少油耗
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
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size(); // 有多少条边

        long long res = 0;

        vector<vector<int>> g(n + 1);

        for (const auto &e : roads)
        { // 双向
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        function<int(int, int)> dfs = [&](int cur, int fa) -> int
        {
            int peopleSum = 1;

            for (auto ne : g[cur])
            {
                if (ne != fa)
                {
                    int peopleCnt = dfs(ne, cur); // 到这个节点有多少乘客
                    peopleSum += peopleCnt;
                    res += (peopleCnt + seats - 1) / seats; // 到这个节点所消耗的汽油
                }
            }

            return peopleSum;
        };

        dfs(0, -1);

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[0,2],[0,3]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

 */
