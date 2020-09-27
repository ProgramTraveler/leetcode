/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* ans=root;
        //对二叉搜索树进行遍历（利用好二叉搜索树的性质）
        while(true)
        {
            if(p->val<ans->val && q->val<ans->val) ans=ans->left; //如果两个值都比当前节点小，就去左节点

            else if(p->val>ans->val && q->val>ans->val) ans=ans->right; //如果两个节点都比当前节点大，就去右节点

            else break; //如果前面都不满足，说明出现分叉了，返回当前的节点
        }
        return ans;
    }
};
// @lc code=end

