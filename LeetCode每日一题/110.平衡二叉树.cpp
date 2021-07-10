/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 返回以该节点为根节点的二叉树的高度，如果不是二叉搜索树了则返回-1
    int depth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = depth(node->left);
        if (leftDepth == -1) return -1; // 说明左子树已经不是二叉平衡树
        int rightDepth = depth(node->right);
        if (rightDepth == -1) return -1; // 说明右子树已经不是二叉平衡树
        return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true; 
    }
};
// @lc code=end

