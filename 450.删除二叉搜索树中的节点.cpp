/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    //把后继的节点删掉
    TreeNode* deleteMinNode(TreeNode* root)
    {
        //如果节点的左子树为NULL,说明它就是后继节点
        if(root->left==NULL)
        {
            //设置一个临时节点来记录右子树的信息
            TreeNode* temp=root->right;
            
            root->right=NULL;

            return temp;
        }
        root->left=deleteMinNode(root->left);

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL; //如果当前的节点为NULL，返回NULL

        if(key<root->val) //如果比查找值大，去左子树查找
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        if(key>root->val) //如果大的话就去右子树查找
        {
            root->right=deleteNode(root->right,key);
            return root;
        }

        //说明找到了与key相同的那个节点的值
        if(root->right==NULL) return root->left; //如果这个节点的右子树为NULL，就让它的左子树代替自己
        if(root->left==NULL) return root->right; //如果这个节点的左子树为NULL,就让它的右子树来代替自己
        
        //如果它的左右子树都不为空，那么就可以用它的前驱（比当前节点小的最大节点）或者后继（比当前节点大的最小节点）
        //这里就用给出后继的方法
        TreeNode* minNode=root->right; //minNode来表示后继的那个节点
        while(minNode->left!=NULL) minNode=minNode->left; //找到最小的那个节点

        //把后继的值给当前的节点
        root->val=minNode->val;
        //把右子树的后继删除，更新root
        root->right=deleteMinNode(root->right);

        return root;  
    }
};
// @lc code=end

