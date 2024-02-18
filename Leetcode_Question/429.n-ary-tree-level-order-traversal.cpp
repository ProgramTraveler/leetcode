/*
 * @lc app=leetcode.cn id=429 lang=cpp
 * @lcpr version=30113
 *
 * [429] N 叉树的层序遍历
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // 层序遍历 & 需要按层进行分类
        if (root == nullptr) return {};

        std::vector<vector<int>> res;
        std::vector<Node*> cur;
        cur.emplace_back(root);

        while (cur.size()) {
            std::vector<int> vals;
            std::vector<Node*> nxt;

            // for (const auto& node : cur) {
            //     vals.emplace_back(node->val);

            //     for (const auto& child : node->children) {
            //         nxt.emplace_back(child);    
            //     }
            // }
            for (const auto& node : cur) {
                vals.emplace_back(node->val);
                nxt.insert(nxt.end(), node->children.begin(), node->children.end());
            }
            res.emplace_back(vals);
            cur = std::move(nxt);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

