/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,int> f,g;
    void dfs(TreeNode *r) {
        if(! r) {
            return ;
        }
        dfs(r -> left);
        dfs(r -> right);
        f[r] = g[r -> left] + g[r -> right] + r -> val;
        g[r] = max(f[r -> left], g[r -> left]) + max(f[r -> right], g[r -> right]);
    }
    int rob(TreeNode* root) {
         int MaxSum;
         dfs(root);
         MaxSum = max(f[root], g[root]);
         return MaxSum;
    }
};
// @lc code=end

