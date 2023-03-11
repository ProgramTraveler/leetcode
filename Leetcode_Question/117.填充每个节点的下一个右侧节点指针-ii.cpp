/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr; //如果节点为空。直接返回
        queue<Node*> q; //定义一个队列
        q.push(root); //把根节点存入队列
        //循环条件为如果队列不为空
        while(!q.empty()){
            int num=q.size(); //队列长度
            Node* last=nullptr; //空节点
            for(int i=1;i<=num;i++) //开始层序遍历
            {
                Node* f=q.front(); //对首节点
                q.pop(); //队首节点出列

                //左节点不为空
                if(f->left!=nullptr) {
                    //左节点入列
                    q.push(f->left);

                }

                //右节点不为空
                if(f->right!=nullptr){
                    //右节点入队列
                    q.push(f->right);

                }
                //当i!=1时,说明last右边有节点（建议画图按流程做一遍） 
                if(i!=1) {
                    last->next=f;
                }
                //因为当i=1时，是最靠左的那个节点，所以就直接给last
                last=f;
            }
        }

        return root;
        
    }
};
// @lc code=end

