/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int idx_sand = 0, idx_stu = 0; // 三明治的下标和学生的下标

        int n = students.size(); 

        while (idx_stu < n) { // 测试一下 vector 的 size 会不会动态更新
            //cout << students.size() << endl;
            if (students[idx_stu] != sandwiches[idx_sand]) {
                students.push_back(students[idx_stu]);
                idx_stu ++;
            } else {
                sandwiches[idx_sand] = -1; // 当前三明治已经被吃了
                idx_sand ++;
                idx_stu ++;
                n = students.size();
            }
        }

        int res = 0;

        for (int i = 0; i < sandwiches.size(); i ++) if (sandwiches[i] != -1) res ++;

        return res;
    }
};
// @lc code=end

