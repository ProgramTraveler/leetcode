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
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        // 总是选择中间的位置左边的数字做为根节点
        int mid = (l + r) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // 递归的构建 左右子树
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};