/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) // 无法合并成一堆
            return -1;

        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // 前缀和

        int memo[n][n][k + 1];
        memset(memo, -1, sizeof(memo)); // -1 表示还没有计算过
        function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
            int &res = memo[i][j][p]; // 注意这里是引用，下面会直接修改 memo[i][j][p]
            if (res != -1) return res;
            if (p == 1) // 合并成一堆
                return res = i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
            res = INT_MAX;
            for (int m = i; m < j; m += k - 1) // 枚举哪些石头堆合并成第一堆
                res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            return res;
        };
        return dfs(0, n - 1, 1);
    }
};
// 超时了
// class Solution {
// public:
//     int mergeStones(vector<int>& stones, int k) {
//         // 连续
//         // vector 的 size 会动态更新
//         vector<int> res;

//         int l = 0, r = 0;

//         int n = stones.size();

//         for (int i = 0; i < n; i ++) {
//             res.push_back(stones[i]);
//         }

//         while (res.size() > 1) {
//             if (res.size() < k) break;

//             int move = INT_MAX;

//             for (int i = 0; i < res.size(); i ++) {

//                 int tem_move = 0;
    
//                 for (int j = i; j < i + k && j < res.size(); j ++) {
//                     tem_move += res[j];
//                 }

//                 if (tem_move < move) {
//                     l = i, r = i + k - 1;

//                     move = tem_move;
//                 }
//             }

//             res[l] = move;

//             vector<int> tem_res;

//             for (int i = 0; i <= l; i ++) tem_res.push_back(res[i]);

//             for (int i = r + 1; i < res.size(); i ++) tem_res.push_back(res[i]);

//             res.clear();

//             for (int i = 0; i < tem_res.size(); i ++) res.push_back(tem_res[i]);
//         }

//         return res.size() == 1 ? res[0] : -1;        
//     }
// };
// @lc code=end

