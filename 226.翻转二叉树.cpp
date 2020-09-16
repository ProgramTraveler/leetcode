/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    void DFS(TreeNode* root)
    {
        //如果节点为空，说明已经遍历完成
        if(!root) return;
    
        TreeNode *tem; //临时节点（做为左右子树交换的中间节点）
        //下面就是左右子树交换
        tem=root->left; 
        root->left=root->right;
        root->right=tem;
        //再去遍历这个节点下的左右子树
        DFS(root->left);
        DFS(root->right);
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        //直接DFS就完是事（看清题目，其实就是把左右子树交换）
        DFS(root);
        return root;
    }
};
// @lc code=end

