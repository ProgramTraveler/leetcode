/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
public:
    //想用深搜的方式来做的,但是问题很大
    /* bool DFS(int left, int right, int up, int down, int m, int n, int i, int j, vector<vector<int>>& temp) {
        

        if (left >= 0) {
            if (temp[i][left] != 1) DFS(left - 1, right, up, down, m, n, i, j, temp);
            else return false;
        }

        if (right <= n -1) {
            if (temp[i][right] != 1) DFS(left, right + 1, up, down,m, n, i, j, temp);
            else return false;
        }

        if (up >= 0) {
            if (temp[up][j] != 1) DFS(left, right, up - 1, down, m, n, i, j, temp);
            else return false;
        }

        if (down <= m -1) {
            if (temp[down][j] != 1) DFS(left, right, up, down + 1, m, n, i, j, temp);
            else return false;
        }
        return (left < 0 && right > n - 1 && up < 0 && down > m -1);
    } */
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int res = 0;

        vector<int> rowsSum(m); //统计每行的和
        vector<int> colsSum(n); //统计每列的和

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1) res ++;
            }
        }

        return res;
        /*
        int res = 0;

        int m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; i ++) {
            for (int j  = 0; j < n; j ++) {
                if (mat[i][j] == 1) {
                    if (DFS(j - 1, j + 1, i - 1, i + 1, m, n, i, j, mat)) {
                        res ++;
                        cout << i << "*" << j << endl;
                    }
                } 
            }
        }

        return res; */
    }
};
// @lc code=end

