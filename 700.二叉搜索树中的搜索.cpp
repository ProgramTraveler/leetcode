/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        /*递归的写法，比较简单
        if(root == NULL) return NULL; //为空，说明没有匹配的数，直接返回NULL

        if(root -> val < val) return searchBST(root -> right, val); //如果当前数比给定值小，就去它的右子树搜索
        else if(root -> val > val) return searchBST(root -> left, val);//如果当前数比给定值大，就去它的左子树搜索

        else return root; //相等，就返回该节点*/
    }
};
// @lc code=end

