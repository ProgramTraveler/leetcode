/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* used[101];//已经拷贝过的指针数组，索引也是值
    
    Node* cloneGraph(Node* node) //递归函数
    {
        if(!node) return node;//判断为空的情况
        if(used[node->val])//如果已经被拷贝过，则可以直接返回数组记录的那个指针
        {
            return used[node->val];
        }

        Node* root = new Node(node->val);//用来做新的拷贝，赋值
        used[node->val] = root;//更新已拷贝指针记录数组

        int n = node->neighbors.size();
        for(int i=0;i<n;i++)//对邻接表每一个元素进行拷贝
        {
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
    }
};
// @lc code=end

