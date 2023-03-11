/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;

        queue<TreeNode*> qu; //层序遍历的常用方法罢了
        qu.push(root);

        while (!qu.empty()) {
            res = 0;
            int n = qu.size(); //如果写在循环里会导致实时更新

            for (int i = 0; i < n; i ++) {
                TreeNode* temp = qu.front();
                res += temp -> val;
                qu.pop();

                if (temp -> left != nullptr) qu.push(temp -> left);
                if (temp -> right != nullptr) qu.push(temp -> right);
            }
        }

        return res;
    }
};
// @lc code=end

