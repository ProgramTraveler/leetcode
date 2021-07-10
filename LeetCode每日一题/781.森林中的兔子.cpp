/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;
        for (int a : answers) m[a]++;
        for (auto a : m) {
            res += (a.second + a.first) / (a.first + 1) * (a.first + 1);
        }
        return res;
    }
};

// @lc code=end

