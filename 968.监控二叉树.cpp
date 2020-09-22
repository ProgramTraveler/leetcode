/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    //1表示有监控，2表示被监控覆盖，0表示既没有监控，也不被覆盖
    int tra(TreeNode* root)
    {
        //空节点，且该节点有覆盖（因为是最后一个节点，而我们尽量在父节点上放监控）
        if(!root) return 2;

        //后序遍历，这样才能做到从下往上遍历
        int left=tra(root->left);
        int right=tra(root->right);

        //如果左右子树都有覆盖
        if(left==2 && right==2) return 0;
        //如果左右子树其中一个没有被覆盖，也不是监控
        if(left==0 || right==0) 
        {
            sum++;
            return 1;
        }
        //如果左右子树其中一个是监控
        if(left==1 || right==1) return 2;

        //不用管这个，只是为了符合int函数有输出
        return -1;
    }
    int minCameraCover(TreeNode* root) 
    {
        sum=0;
        //tra(root); 

        //如果根节点没有被覆盖
        if(tra(root)==0)
        {
            sum++;
        }
        return sum;
    }
private:
    int sum;
};
// @lc code=end

