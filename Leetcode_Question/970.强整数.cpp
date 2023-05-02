/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) { // 枚举这个简单的办法都没有想到
        vector<int> res;
        unordered_set<int> st;

        for (int i = 0; pow(x, i) <= bound; i ++) {
            for (int j = 0; pow(x, i) + pow(y, j) <= bound; j ++) {
                int sum = pow(x, i) + pow(y, j);
                if (!st.count(sum)) st.insert(sum), res.push_back(sum);

                if (y == 1) break;
            }

            if (x == 1) break;
        }

        return res;
    }
};
// @lc code=end

