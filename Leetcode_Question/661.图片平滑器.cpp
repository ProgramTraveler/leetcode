/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // 其实也就是点 -> 点的遍历 判断一下是不是边界
        int row = img.size();

        int col = img[0].size();

        vector<vector<int>> res(row,vector(col, 0));

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                int cnt = 0, idx = 0;
                // 上
                if (i - 1 >= 0) idx += img[i - 1][j], cnt ++;

                // 左上
                if (i - 1 >= 0 && j - 1 >= 0) idx += img[i - 1][j - 1], cnt ++;

                // 右上
                if (i - 1 >= 0 && j + 1 < col) idx += img[i - 1][j + 1], cnt ++;

                // 左
                if (j - 1 >= 0) idx += img[i][j - 1], cnt ++;

                // 左下
                if (i + 1 < row && j - 1 >= 0) idx += img[i + 1][j - 1], cnt ++; 

                // 右
                if (j + 1 < col) idx += img[i][j + 1], cnt ++;

                // 右下
                if (i + 1 < row && j + 1 < col) idx += img[i + 1][j + 1], cnt ++;

                // 下
                if (i + 1 < row) idx += img[i + 1][j], cnt ++;

                idx += img[i][j], cnt ++;

                res[i][j] = idx / cnt;
            }
        }

        return res;
    }
};
// @lc code=end

