/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    //递归的写法，没啥好说的，竟然一下没想到，还是太菜了
    void inorder(vector<int>& answer,TreeNode* root)
    {
        if(!root) return;
        inorder(answer,root->left);
        answer.push_back(root->val);
        inorder(answer,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> answer;
        if(!root) return answer;
        inorder(answer,root);
        return answer;

    }
};
// @lc code=end

