/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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

// 傻* 题目 题目都解释不清楚 举个例子很难？
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // 就是找从根到叶子节点这条路径的总和是不是小于 limit 不小于就标记 最后删除没有标记的节点

        limit -= root -> val;

        if (root -> left == root -> right) // root 是叶子节点
            // 如果limit > 0 说明从根到叶子节点的路径和小于 limit 删除叶子 否则不删除
            return limit > 0 ? nullptr : root;
    
        if (root -> left) root -> left = sufficientSubset(root -> left, limit);
        if (root -> right) root -> right = sufficientSubset(root -> right, limit);

        // 如果有儿子没有被删除 就不删 root 否则删除 root
        return root -> left || root -> right ? root : nullptr;
    }
};
// @lc code=end

