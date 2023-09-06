/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode* > dfs (TreeNode* node) {
        if (node == nullptr) return {0, nullptr};

        auto [left_Height, left_lca] = dfs(node -> left);
        auto [right_Height, right_lca] = dfs(node -> right);

        if (left_Height > right_Height) return {left_Height + 1, left_lca}; // 左边高

        else if (left_Height < right_Height) return {right_Height + 1, right_lca}; // 右边高

        else return {left_Height + 1, node}; // 一样高 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
// @lc code=end

