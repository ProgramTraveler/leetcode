/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void DFS(TreeNode* root,vector<int>& ans){
        if(!root) return;

        DFS(root->left,ans);
        ans.push_back(root->val);

        DFS(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans; //记录中序遍历后的节点值
        DFS(root,ans); //中序遍历
        int Min=INT_MAX; //最小绝对差
        //因为二叉搜索树的中序遍历后是一个有序序列，所以只要比较相邻的两个值的绝对差就行
        for(int i=0;i<ans.size();i++){
            if(i>0){
                Min=min(Min,ans[i]-ans[i-1]);
            }else continue;
        }
        return Min;

    }
};
// @lc code=end

