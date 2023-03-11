/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] ans = new int[5];
        
        for (int i = 0; i < text.length(); i ++) {
            char c = text.charAt(i);
            if (c == 'b') ans[0] ++; //b
            if (c == 'a') ans[1] ++; //a
            if (c == 'l') ans[2] ++; //l
            if (c == 'o') ans[3] ++; //o
            if (c == 'n') ans[4] ++; //n
        }
        ans[2] /= 2;
        ans[3] /= 2;
        int res = ans[0];
        for (int i = 0; i < 5; i ++) res = Math.min(res, ans[i]);
        return res;
    }
}
// @lc code=end

