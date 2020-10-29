/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    void DFS(TreeNode* root){
        //如果这个节点是叶子节点
        if(root->left==nullptr && root->right==nullptr){
            //把叶子节点的值加进temp里
            temp=temp*10+root->val;
            //cout<<temp<<endl;
            //将值传进res数组中
            res.push_back(temp);
            //将叶子节点的值取出
            temp=(temp-(root->val))/10;
            return;
        }
        //如果不是叶子节点，更新temp的值
        temp=temp*10+root->val;
        //如果它的左节点不为空
        if(root->left!=nullptr){
            //向左遍历
            DFS(root->left);
            //如果它的右节点有值的话，就先不取出这个节点的值，没有就取出
            if(root->right==nullptr){
                temp=(temp-(root->val))/10;
            }
            
        }
        //如果它的左节点为空，而右节点不为空
        if(root->right!=nullptr){
            //向右遍历
            DFS(root->right);
            //取出右节点的值
            temp=(temp-(root->val))/10;
        }
        

    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0; //如果节点为空，返回0
        //对这棵树进行前序遍历
        DFS(root);
        //把节点到叶子节点代表的数的值相加
        for(int i=0;i<res.size();i++){
            ans+=res[i];
        }
        //返回最终的答案
        return ans;

    }
private:
    int ans=0;//返回最后的和
    vector<int> res;//记录节点到叶子节点的代表的数字
    int temp=0;//临时记录分支里的数字
};
// @lc code=end

