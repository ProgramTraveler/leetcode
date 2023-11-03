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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;

        dfs(root);

        return res;
    }

private:
    int res , k;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        if (k == 0) return;
        if (--k == 0) res = node->val;
        dfs(node->right);
    }
};