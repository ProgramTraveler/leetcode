/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void DFS(TreeNode* root, vector<int>& nums) {
        if (root -> left == nullptr && root -> right == nullptr) {
            nums.push_back(root -> val);
            return;
        }
        if (root -> left) {
            DFS(root -> left, nums);
        }
        if (root -> right) {
            DFS(root -> right, nums);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> Root1;
        vector<int> Root2;
        DFS(root1, Root1);
        DFS(root2, Root2);
        if (Root1.size() != Root2.size()) return false;
        for (int i = 0; i < Root1.size(); i ++) {
            if (Root1[i] != Root2[i]) return false;
        }
        return true; 
    }
};
// @lc code=end

