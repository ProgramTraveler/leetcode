/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
     bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==nullptr&&q==nullptr)
        {
            return true;
        }
        if(p!=nullptr&&q!=nullptr&&p->val==q->val)
        {
           return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right); //这一步是关键
        }
        else
        {
            return false;
        }

    }
};
// @lc code=end

