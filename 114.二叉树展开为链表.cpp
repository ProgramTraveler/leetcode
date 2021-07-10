/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void Tree(TreeNode *root,vector<TreeNode*> &ans)
    {
        if(root==nullptr)  return;
        ans.push_back(root);
        Tree(root->left,ans);
        Tree(root->right,ans);
    }
    void flatten(TreeNode* root) 
    {
        vector<TreeNode*> ans;
        Tree(root,ans);
        TreeNode *new_root=new TreeNode();
        for(auto val:ans)
        {
            new_root->left=nullptr;
            new_root->right=val;
            new_root=new_root->right;
        } 
        new_root=new_root->right;
    }
};
// @lc code=end

