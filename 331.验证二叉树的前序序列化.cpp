/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        int i = 0;
        stack<int> stk;
        stk.push(1);
        while (i < n) {
            if (stk.empty()) {
                return false;
            }
            if (preorder[i] == ',') {
                i++;
            } else if (preorder[i] == '#'){
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                i++;
            } else {
                // 读一个数字
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    }
};
// @lc code=end

