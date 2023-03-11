/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(TreeNode* root,vector<string>& answer,string path)
    {
        if(root!=nullptr) //判断当前节点是否为空
        {
            path+=to_string(root->val);//加上的节点
            if(root->left==NULL && root->right==NULL) //判断当前的节点是否为叶子节点
            {
                answer.push_back(path); //将之前的路径存储在answer中
                return;
            }
            else
            {
                //不是叶子节点的话就加上"—>"这个符号（答案要求），并对它进行左右节点的遍历
                path+="->";
                dfs(root->left,answer,path);
                dfs(root->right,answer,path);
            }
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> answer;//记录所有的路径
        string path;//记录当前的其中一条路
        //if(root==nullptr) return answer;
        dfs(root,answer,path);
        return answer;
    }
};
// @lc code=end

