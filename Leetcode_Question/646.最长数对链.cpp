/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int index = INT_MIN, res = 0;

        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) { //按第二个位置的数字排序
            return a[1] < b[1];
        });

        for (auto &cur : pairs) {
            if (cur[0] > index) {
                res ++;
                index = cur[1];
            }
        }
        
        return res;
    }
};
// @lc code=end

