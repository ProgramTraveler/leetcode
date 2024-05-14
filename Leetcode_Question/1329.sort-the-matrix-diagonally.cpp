/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30122
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.at(0).size();
        vector<int> a(min(m, n));
        for (int k = 1 - n; k < m; k ++) { // k = i - j
            int left_i = max(k, 0), right_i = min(k + n, m);
            for (int i = left_i; i < right_i; i ++) {
                a.at(i - left_i) = mat[i][i - k];
            }
            sort(a.begin(), a.begin() + (right_i - left_i));
            for (int i = left_i; i < right_i; i ++) {
                mat[i][i - k] = a.at(i - left_i);
            }
        }
        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

