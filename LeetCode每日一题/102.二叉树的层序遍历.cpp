/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void DFS(TreeNode* root,vector<vector<int>>& ans,int level)
    {
        if(!root) return; //为空，直接返回
        if(level>=ans.size()) ans.push_back(vector<int>()); //如果当前深度大于当前ans的行，就开辟一个新的行
        ans[level].push_back(root->val); //把新的节点放进该点的level（同时相同level的值也会放进）
        DFS(root->left,ans,level+1); //向下一个左子树深度遍历
        DFS(root->right,ans,level+1); //向下一个右子树深度遍历
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        DFS(root,ans,0);
        return ans;
    }
};
// @lc code=end

