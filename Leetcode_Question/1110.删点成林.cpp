/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // 把删除节点的左右子树的节点存入就好了

        vector<TreeNode*> res;

        if (root == nullptr) return res;

        // 为了方便查找 放入 map 中
        unordered_map<int, bool> al;

        for (auto &n : to_delete) al[n] = true;

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) return;

            // TreeNode* tem_node = root;

            dfs(root -> left);
            if (root -> left && al[root -> left -> val]) {
                if (root -> left -> left) res.emplace_back(root -> left -> left);

                if (root -> left -> right) res.emplace_back(root -> left -> right);

                root -> left = nullptr;
            }

            dfs(root -> right);
            if (root -> right && al[root -> right -> val]) {
                if (root -> right -> left) res.emplace_back(root -> right -> left);

                if (root -> right -> right) res.emplace_back(root -> right -> right);

                root -> right = nullptr;
            }

        };

        dfs(root);

        // 判断一下根节点
        if (al[root -> val]) {
            if (root -> left) res.emplace_back(root -> left);

            if (root -> right) res.emplace_back(root -> right);
        } else res.emplace_back(root);

        return res;
    }
};

/* 

灵神的思路

class Solution {
    vector<TreeNode *> ans;
    unordered_set<int> s;

    TreeNode *dfs(TreeNode *node) {
        if (node == nullptr) return nullptr;
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        if (!s.count(node->val)) return node;
        if (node->left) ans.push_back(node->left);
        if (node->right) ans.push_back(node->right);
        return nullptr;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (int x: to_delete) s.insert(x);
        if (dfs(root)) ans.push_back(root);
        return ans;
    }
};
*/
// @lc code=end

