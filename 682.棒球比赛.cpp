/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for (string c : ops) {
            if (c == "C")
                ans.pop_back();
            else if (c == "D")
                ans.push_back(ans[ans.size() - 1] * 2);
            else if (c == "+")
                ans.push_back(ans[ans.size() - 1] + ans[ans.size() - 2]);
            else
                ans.push_back(stoi(c));
        }
        int res = 0;
        for (int i = 0; i < ans.size(); i ++)
            res += ans[i];
        return res;
    }
};
// @lc code=end

