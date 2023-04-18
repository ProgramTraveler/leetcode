/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root) {
        int res = INT_MIN;

        int up = root -> val, low = root -> val;


        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int up, int low) { // 不能把 up 和 low 变成全局的 不然记录就是整棵树的最大值和最小值
            if (root == nullptr) return;

            res = max(res, max(abs(root -> val - up), abs(root -> val - low)));
            
            up = max(up, root -> val);
            low = min(low, root -> val);

            dfs(root -> left, up, low);
            dfs(root -> right, up, low);
            
        };

        dfs(root, up, low);

        return res;
    }
};
// @lc code=end

