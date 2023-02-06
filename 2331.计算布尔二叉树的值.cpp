/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode* root) { // 感觉前序遍历应该是可以做的
        if (root -> left == nullptr || root -> right == nullptr) return root -> val; // 完整二叉树其实节点只有 0 和 2

        if (root -> left -> val != 0 || root -> left -> val != 1)  root -> left -> val = evaluateTree(root -> left); // 当前不是叶子节点就接着向下遍历

        if (root -> right -> val != 0 || root -> right -> val != 1) root -> right -> val = evaluateTree(root -> right);

        /*if (root -> left -> val == 1 || root -> left -> val == 0) { // 是叶子节点
            if (root -> val == 2) return (root -> left -> val) || (root -> right -> val);

            if (root -> val == 3) return (root -> left -> val) && (root -> right -> val); 
        }*/

        return root -> val == 2 ? (root -> left -> val) || (root -> right -> val) : (root -> left -> val) && (root -> right -> val);
    }
};
// @lc code=end

