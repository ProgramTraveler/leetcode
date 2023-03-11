/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void Middle(TreeNode* root)
    {
        if(!root) return;

        Middle(root->left);

        count=(root->val==temp_val) ? count+1 : 1; //如果和之前的数相等，数目加一，否则就置为1
        //cout<<"c:"<<count<<endl;

        if(count> Max) //如果这个数的数目比之前统计Max的大，就更新Max和ans
        {
            Max=count; //更新Max
            //cout<<Max<<endl;
            ans=vector<int>(1,root->val); //更新ans
        }
        else if(count==Max) //如果和Max相等，就放进ans里
        {
            ans.push_back(root->val);
        }

        temp_val=root->val; //更新temp_val

        Middle(root->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        Middle(root);
        return ans;    
    }

private:
    int Max=INT_MIN;
    int count=0;
    int temp_val=0;
    vector<int> ans;

};
// @lc code=end

