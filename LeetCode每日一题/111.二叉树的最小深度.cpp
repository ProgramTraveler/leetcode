/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int dfs(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left==NULL || root->right==NULL)
        {
             if(root->left==NULL)
            {
                return dfs(root->right)+1;
            }
            else
            {
                return dfs(root->left)+1;
            }
        }
        int leftNum=dfs(root->left);
        int rightNum=dfs(root->right);
        return min(leftNum,rightNum)+1;
    }
    int minDepth(TreeNode* root) 
    {
        return dfs(root);
    }
};
// @lc code=end

