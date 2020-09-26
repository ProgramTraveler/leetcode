/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void DFS(TreeNode* root,int sum,int temp_sum)
    {
        
        if(root->left==NULL && root->right==NULL) //如果当前节点的左右节点都为NULL，说明到叶子节点了
        {
            if(temp_sum==sum) //如果分支的值和目标值一样，就存入最终答案
            {
                ans.push_back(temp);
                return;
            }
            else return; //不相等就直接返回
        }

        if(root->left) //如果它的左节点不为NULL
        {
            temp_sum+=root->left->val; //更新temp_sum
            temp.push_back(root->left->val); //把当前值放入临时数组

            DFS(root->left,sum,temp_sum); //递归
            //回溯
            temp.pop_back(); 
            temp_sum-=root->left->val;

        }

        if(root->right) //如果它的右节点不为NULL
        {
            temp_sum+=root->right->val;
            temp.push_back(root->right->val);
            DFS(root->right,sum,temp_sum); 
            temp.pop_back();
            temp_sum-=root->right->val;
        }

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(!root) return ans; //特殊情况情况直接返回
        temp.push_back(root->val);//先把根节点存入
        DFS(root,sum-root->val,0);
        return ans;   
    }

private:
    vector<vector<int>> ans; //保存最后的答案
    vector<int> temp; //保存每个分支的答案
};
// @lc code=end

