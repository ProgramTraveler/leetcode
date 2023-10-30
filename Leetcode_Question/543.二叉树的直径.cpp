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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        function<int(TreeNode*)> depth = [&](TreeNode* node) {
            if (node == nullptr) return 0;

            int L = depth(node -> left);
            int R = depth(node -> right);
            
            res = max(res, L + R + 1);

            return max(L, R) + 1;
        };

        depth(root);

        return res - 1;
    }
};