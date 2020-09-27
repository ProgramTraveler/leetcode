/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode* delate(TreeNode* root)
    {
        if(!root) return NULL;

        root->left=delate(root->left);
        root->right=delate(root->right);

        if(!root->left && root->val==0 && !root->right) return NULL; //如果当前节点为NULL，而且值是0

        return root;
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        return delate(root);   
    }
};
// @lc code=end

