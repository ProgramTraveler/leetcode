/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = INT_MIN, l = 0, r = 0;
         
        vector<int> num; // 记录水果的种类
        vector<int> coordinate; // 记录最初水果的位置 这是对数据的优化 不然每次就移动一步在最后会超时

        if (fruits.size() == 1) return 1;

        while (l <= r && r < fruits.size()) {
            if (num.size() == 0 || (num.size() == 1 && num[0] != fruits[r]))  num.push_back(fruits[r]), coordinate.push_back(r), r ++;

            else if (fruits[r] != num[0] && fruits[r] != num[1]) {
                res = max(res, r - l);
                l = coordinate[1];
                r = l;
                num.clear();
                coordinate.clear();
            } else r ++;
        }

        res = max(res, r - l);
        
        return res;
    }
};
// @lc code=end

