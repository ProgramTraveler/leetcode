/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Middle(TreeNode* root) //对二叉树搜索树进行中序遍历
    {
        if(!root) return; //结束条件

        //中序遍历
        Middle(root->left);
        ans.push_back(root->val); //把中序遍历的结果存入数组
        Middle(root->right);
    }
    bool isValidBST(TreeNode* root) 
    {
        Middle(root);

        //在对数组进行检查，如果是二叉搜索树，那么它的中序遍历一定是有一个递增数组
        for(int i=0;i<ans.size();i++)
        {
            if(i>0 && ans[i]>ans[i-1]) continue; //比较当前数和前一个数
            if(i==0) continue; //第一个数前面没数，直接跳过
            else return false;
        }
        return true;
    }
private:
    vector<int> ans;
};
// @lc code=end

