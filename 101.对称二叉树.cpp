/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    //通过镜像来比较
    bool cheak(TreeNode* q,TreeNode* p){
        if(!q && !p) return true; //如果两棵树的节点都为空，说明对称而且已经结束，返回true
        if(!q || !p) return false; //如果两棵树的其中一个为空，说明不对称，返回false
        if(q->val!=p->val) return false; //如果两棵树的节点值不一样，直接返回false
        return cheak(q->left,p->right) && cheak(q->right,p->left); //否则就递归
    }
    bool isSymmetric(TreeNode* root) {
        return cheak(root,root);
    }
};
// @lc code=end

