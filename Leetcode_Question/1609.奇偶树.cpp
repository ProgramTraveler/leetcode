/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> que; //记录树的层序节点
        que.push(root); //将根点放入
        int lay = 0; //记录层数
        while (!que.empty()) {
            int count = que.size(); //当前层的节点个数
            int flag = (++ lay) % 2; //判断当前层的奇偶性
            int last = 0; //记录上一个节点的数值
            for (int i = 0; i < count; i ++) {
                TreeNode* node = que.front(); //获得当前节点
                que.pop(); //当前节点出队

                if ((node -> val) % 2 != flag) return false; //不满足奇偶层次性
                
                if ((node -> val) % 2 == flag) { //满足奇偶性

                    if (flag == 0 && i > 0 && node -> val - last >= 0) //不满足偶数层条件
                        return false;
                    if (flag == 1 && i > 0 && node -> val - last <= 0) //不满足奇数层条件
                        return false;
                }
                last = node -> val; //保存节点数值
                //该节点的左右子树入队
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
        }
        return true;
    }
};
// @lc code=end

