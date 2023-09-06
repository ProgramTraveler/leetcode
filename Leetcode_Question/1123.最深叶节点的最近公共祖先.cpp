/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // 最深叶子节点 -> 如果只有一个叶子节点是最深的 那么它自己就是自己的父节点
        // 记录最深的叶子节点的父节点 -> 那不是要记录一条完整的路径？太麻烦了
        // 返回的结果是一颗子树
        return dfs(root).second; // 返回子树
    }
};
// @lc code=end

