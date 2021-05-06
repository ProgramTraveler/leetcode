/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1, first);
        for (int i = 1; i < encoded.size() + 1; i ++) {
            res[i] = encoded[i - 1] ^ res[i - 1];
        }
        return res;
    }
};
// @lc code=end

