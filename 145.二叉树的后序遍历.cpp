/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    //递归就完事（但容易爆栈），推荐还是把迭代给学了
    void postorder(vector<int>& answer,TreeNode* root)
    {
        if(!root) return;
        postorder(answer,root->left);
        postorder(answer,root->right);
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> answer;
        if(!root) return answer;
        postorder(answer,root);
        return answer;   
    }
};
// @lc code=end

