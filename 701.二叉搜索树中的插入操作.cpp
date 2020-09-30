/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* DFS(TreeNode* root,int val){
        //如果遇到空节点，就插入val
        if(!root){
            TreeNode* Node=new TreeNode(val);
            return Node;
        }
        //按二叉搜索树的规律去寻找插入点
        if(root->val>val) root->left=DFS(root->left,val);
        if(root->val<val) root->right=DFS(root->right,val);

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return DFS(root,val);
    }
};
// @lc code=end

