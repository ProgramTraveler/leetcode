/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    set<int> s; //set会进行自动排序，并且不会有重复
    void dfs(TreeNode* root)
    {
        s.insert(root -> val);
        if (root -> left) dfs(root -> left);
        if (root -> right) dfs(root -> right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)return -1;
        dfs(root);
        if (s.size() < 2)return -1;
        set<int>::iterator it = s.begin(); //获得第一个节点的位置地址
        it ++; //地址加一
        return *it; //返回第二个节点的值
    }
};
// @lc code=end

