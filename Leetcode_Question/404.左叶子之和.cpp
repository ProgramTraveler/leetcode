/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int  DFS(TreeNode* root)
    {
        int sum=0;

        if(!root) return 0; //特殊情况，如果树为空，直接返回0

        //如果树的左节点不为NULL，再去判断该节点是否为叶子节点（即该节点的度为0）
        if(root->left!=NULL)
        {
            if(root->left->left==NULL && root->left->right==NULL) sum+=root->left->val; //保留该叶子节点的值
            //不是叶子节点就继续向下遍历
            else sum+=DFS(root->left);
        }
        //如果右节点不为NULL，就继续向下遍历
        if(root->right!=NULL)
        {
            //向下遍历
            sum+=DFS(root->right);
        }

        return sum;
    } 
    int sumOfLeftLeaves(TreeNode* root) 
    {
        //递归遍历树的所有节点
        return DFS(root);
    }

};
// @lc code=end

