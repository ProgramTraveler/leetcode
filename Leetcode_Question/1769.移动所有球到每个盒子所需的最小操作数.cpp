/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans, idx;

        for (int i = 0; i < boxes.size(); i ++) if (boxes[i] == '1') idx.push_back(i);

        for (int i = 0; i < boxes.size(); i ++) {
            int res = 0;
            
            for (int j = 0; j < idx.size(); j ++) res += abs(idx[j] - i);
            
            ans.push_back(res);
        }

        return ans;
    }
};
// @lc code=end

