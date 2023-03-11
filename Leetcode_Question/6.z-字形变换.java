/*
 * @lc app=leetcode.cn id=6 lang=java
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
    static int N = 1010;
    static char[][] g = new char[N][N];
    static int[] idxs = new int[N];
    public String convert(String s, int m) {
        if (m == 1) return s;
        int n = s.length();
        Arrays.fill(idxs, 0);
        for (int i = 0, j = 0, k = 1; i < n; i++) {
            g[j][idxs[j]++] = s.charAt(i);
            j += k;
            if (j < 0) {
                j += 2; k = 1;
            } else if (j == m) {
                j -= 2; k = -1;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < idxs[i]; j++) {
                sb.append(g[i][j]);
            }
        }
        return sb.toString();
    }
}
// @lc code=end

