/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* Fun(TreeNode* root, int l, int h) {
        if (!root) return nullptr;


        /*if (root -> left != nullptr && root -> left -> val < l) {
            root -> left = root -> left ->right;
            Fun(root, l, h);
        }
        if (root -> right != nullptr && root -> right -> val > h) {
            root -> right = root -> right -> left;
            Fun(root, l, h);
        }
        Fun(root -> left, l, h);
        Fun(root -> right, l, h);*/
        if (root -> val < l) return Fun(root -> right, l, h);
        else if (root -> val > h) return Fun(root -> left, l, h);
        else {
            root -> left = Fun(root -> left, l, h);
            root -> right = Fun(root -> right, l, h);
            return root;
        }

    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //对该二叉树进行前序搜索
        /*if (root -> val < low) root = root -> right;

        if(root -> val > high) root = root -> left;*/

        return Fun(root, low, high);
    }
};
// @lc code=end

