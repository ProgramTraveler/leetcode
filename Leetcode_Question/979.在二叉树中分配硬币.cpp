/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int ans = 0;

    pair<int, int> dfs(TreeNode *node) {
        if (node == nullptr)
            return {0, 0};
        auto [coins_l, nodes_l] = dfs(node->left);
        auto [coins_r, nodes_r] = dfs(node->right);
        int coins = coins_l + coins_r + node->val; // 子树硬币个数
        int nodes = nodes_l + nodes_r + 1; // 子树节点数
        ans += abs(coins - nodes);
        return {coins, nodes};
    }

public:
    int distributeCoins(TreeNode *root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

