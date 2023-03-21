/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*> qu;
        vector<TreeNode*> tem;
        
        vector<vector<int>> res;
        vector<int> cnt;

        if (!root) return res;


        qu.push_back(root);
        // cnt.push_back(root -> val);

        // res.push_back(cnt);

        // cnt.clear();

        while (qu.size() != 0) {
            tem = qu;

            qu.clear();

            for (int i = 0; i < tem.size(); i ++) {
                if (tem[i] -> left != nullptr) qu.push_back(tem[i] -> left);

                if (tem[i] -> right != nullptr) qu.push_back(tem[i] -> right);

                cnt.push_back(tem[i] -> val);
            }

            res.push_back(cnt);

            cnt.clear();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

