/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void Middle(TreeNode* root)
    {
        if(!root) return; //直到该节点为NULL，说明已经到最后的那个节点

        Middle(root->right); //先遍历它的右节点
        root->val+=sum; //转换为累加树对应的节点
        sum=root->val; //跟新sum
        Middle(root->left); //遍历它的左节点
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        Middle(root); //对二叉搜索树进行逆中序遍历
        return root;

    }
private:
    int sum=0;
};
// @lc code=end

