/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> left(2, 0);
        vector<int> right(2, 0);
        queue<TreeNode*> que; //记录层序节点
        que.push(root);
        int level = 0;
        int leftNode = root -> val, rightNode = root -> val;
        while (!que.empty()) {
            int countLevel = que.size(); //当前层的节点个数

            for (int i = 0; i < countLevel; i ++) { //对当前层的节点进行遍历
                TreeNode* node = que.front();
                que.pop();
                if (node -> val == x) { 
                    left[0] = leftNode;
                    left[1] = level;
                }
                if (node -> val == y) {
                    right[0] = rightNode;
                    right[1] = level; 
                }
                if (node -> left) {
                    que.push(node -> left);
                    if (node -> left -> val == x) leftNode = node -> val;
                    if (node -> left -> val == y) rightNode = node -> val;
                };
                if (node -> right) {
                    que.push(node -> right);
                    if (node -> right -> val == x) leftNode = node -> val;
                    if (node -> right -> val == y) rightNode = node -> val; 
                }
            }
            level ++;
        }
        if (left[0] != right[0] && left[1] == right[1]) return true;
        else return false;
    }
};
// @lc code=end

