/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    void DFS(TreeNode *root,vector<vector<int>>& tem,int level)
    {
        if(!root) return; //终止条件
        if(level>=tem.size()) tem.push_back(vector<int>()); //如果当前的深度比tem数组大，就再开辟新的一行
        tem[level].push_back(root->val); //把新的节点放进该点的level（同时相同level的值也会放进）
        DFS(root->left,tem,level+1);
        DFS(root->right,tem,level+1);
    }
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        vector<vector<int>> tem;
        //ans.push_back(root->val);
        DFS(root,tem,0);
        //上面就是层序遍历（建议做一遍二叉树得层序遍历）
        //把层序遍历后的二叉树以数组的形式储存后，计算它每一层的平均值
        vector<int> num; //记录每一层有多少个数字
        for(int i=0;i<tem.size();i++)
        {
            num.push_back(0); //每有一个新的一层，就开辟一个新的空间
            num[i]=tem[i].size();
        }
        for(int i=0;i<tem.size();i++) //计算每一层的平均值
        {
            double av=0.0; //储存每一层的和
            for(int j=0;j<tem[i].size();j++)
            {                
                av+=tem[i][j];
            }
            ans.push_back((double)av/num[i]); //把最终结果储存并转换为double的数据类型
        }
        return ans;
    }
};
// @lc code=end

