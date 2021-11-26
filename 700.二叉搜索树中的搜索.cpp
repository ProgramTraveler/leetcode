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
    
        //迭代的写法，老写递归没意思
       TreeNode* node = root;
        while (node) {
            /*这一步的思路有问题，按道理不应该是三个 if 连着写，这样会是同级判断，一路执行下去
            if (node -> val > val) node = node -> left;
            if (node -> val == val) return node;
            if (node -> val < val) node = node -> right;
            */
            //这样写才是正确的，分级执行
            if (node -> val == val) return node;
            else if (node -> val > val) node = node -> left;
            else node = node -> right;

            //下面这样写更简洁，但执行过程是一样的
            //if (node -> val == val) return node;
            //node = val < node -> val ? node -> left : node -> right;
        }
        return nullptr;
    }
};
// @lc code=end

