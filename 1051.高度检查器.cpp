/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
    void quick_sort(vector<int>& expected, int l, int r) {
        if (l >= r) return ;

        int x = expected[l], i = l - 1, j = r + 1; //对参照值的选择会对时间复杂度产生很大的影响

        while (i < j) {
            do i ++; while (expected[i] < x);
            do j --; while (expected[j] > x);
            if (i < j) swap(expected[i], expected[j]);
        }

        quick_sort(expected, l, j);
        quick_sort(expected, j + 1, r);
    }

    int heightChecker(vector<int>& heights) {
        int res = 0;

        vector<int> expected(heights.size(), 0);

        for (int i = 0; i < heights.size(); i ++) expected[i] = heights[i]; //赋值
        
        quick_sort(expected, 0, heights.size() - 1);

        for (int i = 0; i < heights.size(); i ++) {
            if (heights[i] != expected[i]) res ++;
        }
 
        return res;
    }
};
// @lc code=end

