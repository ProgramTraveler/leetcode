/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 * @lcpr version=30111
 *
 * [2661] 找出叠涂元素
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
    using ll = long long;
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size(); // 行数
        int col = mat[0].size(); // 列数

        std::unordered_map<int, ll> num_map_row;
        std::unordered_map<int, ll> num_map_col;

        std::unordered_map<int, ll> row_map_sum;
        std::unordered_map<int, ll> col_map_sum;
        
        // init
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                num_map_row[mat[i][j]] = i;
                num_map_col[mat[i][j]] = j;

                row_map_sum[i] += mat[i][j];
                col_map_sum[j] += mat[i][j];
            }
        }

        int idx = 0;
        int n = arr.size();
        for (; idx < n; idx ++) {
            int tem_row = num_map_row[arr[idx]];
            int tem_col = num_map_col[arr[idx]];

            row_map_sum[tem_row] -= arr[idx];
            col_map_sum[tem_col] -= arr[idx];

            if (row_map_sum[tem_row] == 0 || col_map_sum[tem_col] == 0) break;
        }

        return idx;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2]\n[[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [2,8,7,4,1,3,5,6,9]\n[[3,2,5],[1,4,6],[8,7,9]]\n
// @lcpr case=end

 */

