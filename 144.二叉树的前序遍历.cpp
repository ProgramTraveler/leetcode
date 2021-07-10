/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    //之前使用的是递归的方法写的，再次遇到了这个题，准备写一次迭代的
    /*vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root)
       {
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
       }
        return ans;
    }*/
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;//记录前序遍历的结果
        if(!root) return ans; 
        //栈，储存节点
        stack<TreeNode*> stk;
        //一个临时节点，方便对循环语句进行判断
        TreeNode* node=root;
        //只有当栈为空，而且节点也为空才说明对这颗树的遍历结束
        while(!stk.empty() || node!=nullptr){
            //一直遍历它的左节点，找到最底层的左节点
            while(node!=nullptr){
                //记录左节点的值
                ans.push_back(node->val);
                //记录左边的节点
                stk.push(node);
                //更新左节点
                node=node->left;
            }
            //获取栈顶元素
            node=stk.top();
            //将栈顶元素弹出
            stk.pop();
            //向右遍历
            node=node->right;
        }
        return ans; 
    }
};
// @lc code=end

