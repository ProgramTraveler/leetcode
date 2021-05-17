/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void dfs (int cur, int n, int k) {
        if (temp.size() + (n - cur + 1) < k) //如果当前的个数加上剩下的数不能满足情况，剪枝
            return;
        if (temp.size() == k) { //满足条件，保存数组
            res.push_back(temp);
            return;
        }
        //保留当前位置的值
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        //不保留当前位置的值
        temp.pop_back();
        dfs(cur + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
private:
    vector<int> temp; //记录临时位置的值
    vector<vector<int>> res; //记录最终的结果
};
// @lc code=end

