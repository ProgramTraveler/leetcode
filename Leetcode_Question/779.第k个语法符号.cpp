/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        /*
        本来是想通过构造出二叉树来解题 但最后的 层数太大 应该是构造的部分超时了

        vector<int> tree(pow(2, n), -1);

        tree[1] = 0;

        int N = pow(2, n) - 1, num = 1;

        int idx = 1;

        while (num < N) {
            if (tree[idx] == 0) tree[idx * 2] = 0, tree[idx * 2 + 1] = 1;
            else tree[idx * 2] = 1, tree[idx * 2 + 1] = 0;
            num += 2;
            idx ++;
        }

        int co = pow(2, n - 1); 
        idx = 1;
 
        while (idx < k) co ++, idx ++;

        return tree[co];
        */

        if (n == 1) return 0;

        int res = kthGrammar(n - 1, (k + 1) / 2); // 通过从底层向上寻找

        if (res == 0) return k % 2 ? 0 : 1;

        else return k % 2 ? 1 : 0; 
    }
};
// @lc code=end

