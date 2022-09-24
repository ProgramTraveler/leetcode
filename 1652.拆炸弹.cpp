/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);

        bool flag  = true;

        if (k == 0) return res;

        if (k < 0) {
            reverse(code.begin(), code.end());
            k = abs(k);
            flag = false;
        }

        for (int i = 0; i < code.size(); i ++) {
            int index = i + 1, num = k; //下标指示
            
            while (num > 0) {
                res[i] += code[index % code.size()];
                num --;
                index ++;
            }

            cout << endl;
        }
        if (! flag) reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

