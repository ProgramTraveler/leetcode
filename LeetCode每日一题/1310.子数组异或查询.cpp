/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xors(n + 1);
        for (int i = 0; i < arr.size(); i ++) {
            xors[i + 1] = arr[i] ^ xors[i]; 
        }
        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i ++) {
            res[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return res;
    }
};
// @lc code=end

