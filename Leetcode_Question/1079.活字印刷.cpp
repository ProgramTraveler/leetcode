/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
/*class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> al;
        
        string tem {};

        function<void(int)> dfs = [&](int i) {
            if (i == tiles.size()) {
                al.insert(tem);

                return;
            }

            dfs(i + 1); // 不选

            tem.push_back(tiles[i]);
            dfs(i + 1); // 选
            tem.pop_back();
        };

        dfs(0);

        return al.size();
    }
};*/

const int MX = 8;
int c[MX][MX];

int init = []() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // 预处理组合数
    }
    return 0;
}();

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> counts;
        for (char c: tiles) counts[c]++; // 统计每个字母的出现次数
        int n = tiles.length(), m = counts.size(), f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1; // 构造空序列的方案数
        int i = 1;
        for (auto &[_, cnt]: counts) { // 枚举第 i 种字母
            for (int j = 0; j <= n; j++) // 枚举序列长度 j
                for (int k = 0; k <= j && k <= cnt; k++) // 枚举第 i 种字母选了 k 个
                    f[i][j] += f[i - 1][j - k] * c[j][k];
            i++;
        }
        return accumulate(f[m] + 1, f[m] + n + 1, 0);
    }
};
// @lc code=end

