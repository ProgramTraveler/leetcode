/*
 * @lc app=leetcode.cn id=717 lang=java
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length - 1;
        int index = 0;
        while (index <= n) {
            if (index == n && bits[index] == 0) return true;

            if (bits[index] == 1) index += 2;
            else index += 1;
        }

        return false;
        
    }
}
// @lc code=end

