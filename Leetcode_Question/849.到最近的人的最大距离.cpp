/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // 关键是 所有的位置的下标
        // 只会计算 距离最近的位置 但是最近的位置 最大 也就是说计算的是最靠近空位的座位的位置
        // 双指针？ 从空位向左右遍历？
        // 时间复杂度？
        // 要不顺便保存一下最接近的 左右有人的座位

        int res = 0;

        vector<int> pe; // 每个座位的下标
        for (int i = 0; i < seats.size(); i ++) if (seats[i] == 1) pe.emplace_back(i);

        vector<int> em; // 每个空位的下标
        for (int i = 0; i < seats.size(); i ++) if (seats[i] == 0) em.emplace_back(i);

        // 获取最近的两个座位下标
        int l = pe.size() - 1, r = 0;

        for (int i = 0; i < em.size(); i ++) {
            if (l < 0) l = r; // 更新 l
            if (r >= pe.size()) r = l; // 更新 r

            while (l >= 0 && pe[l] > em[i]) { // 如果最左边的比当前位置的靠右

                if (pe[l] < em[i]) break; // 左边 最接近的

                l --; // 向左移动
            }


            while (r < pe.size() && pe[r] < em[i]) { // 如果最右边的比当前位置的靠左

                if (pe[r] > em[i]) break; // 右边最接近的

                l = r; // 更新 l 位置

                r ++; // 向右移动
            }

            int tem_l = INT_MAX, tem_r = INT_MAX;

            if (l >= 0) tem_l = min(tem_l, em[i] - pe[l]);

            if (r < pe.size()) tem_r = min(tem_r, pe[r] - em[i]);

            res = max(min(tem_l, tem_r), res);

            // cout << tem_l << " " << tem_r << endl;
            // cout << l << " " << r << " " << em[i] << " " << res << endl;
            // cout << "-----" << endl;
        }


        return res;
    }
};
// @lc code=end

