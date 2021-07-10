/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* DFS(TreeNode* t1,TreeNode* t2)
    {
        //如果两数的该节点都为NULL，就返回NULL
        if(!t1 && !t2) return NULL;
        //如果t1为空，那么就返回t2的节点
        if(t1==NULL) return t2;
        //如果t2为空，返回t1的节点
        if(t2==NULL) return t1;
        //如果两节点都存在，把它们的和作为新节点
        TreeNode* t3=new TreeNode(t1->val+t2->val);
        //继续向下遍历
        t3->left=DFS(t1->left,t2->left);
        t3->right=DFS(t1->right,t2->right);

        return t3;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
    
        return DFS(t1,t2);
    }
};
// @lc code=end

