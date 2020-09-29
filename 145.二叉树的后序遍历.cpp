/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    //递归就完事（但容易爆栈），推荐还是把迭代给学了
    /*void postorder(vector<int>& answer,TreeNode* root)
    {
        if(!root) return;
        postorder(answer,root->left);
        postorder(answer,root->right);
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> answer;
        if(!root) return answer;
        postorder(answer,root);
        return answer;   
    }*/


    //迭代(第一次用递归做的，这次又遇到了就用迭代试试)
    //和迭代的前序遍历差不多（前序是中左右，后序是左右根），就是多个反序操作
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans; //记录每次节点的值
        if (!root) return ans; //为空就直接返回空

        stack<TreeNode *> stk; //现实中的栈
        stk.push(root); //先把根节点存入
        //结束条件就是当栈为空
        while(!stk.empty()){
            //把栈顶元素赋值
            root=stk.top();
            //把弹出的元素的值存入ans
            ans.push_back(root->val);
            //把栈顶元素弹出
            stk.pop();
            //再分别把左节点和右节点压入栈
            if(root->left) stk.push(root->left);
            if(root->right) stk.push(root->right);
        }
        //在把ans里的元素反序
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

