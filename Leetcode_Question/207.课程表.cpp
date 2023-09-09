/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& pre) {
//         // 所有课程对互不相同
//         // 1 -> 学过 0 -> 未学

//         vector<int> co(numCourses, 1); // 初始状态是所有课程都学了

//         // 查看哪些课程是需要前置课程的 将需要前置的条件设为未学
//         int row = pre.size();

//         if (row <= 0) return true; // 所有课程不需要前置条件

//         int col = pre[0].size();
//         unordered_map<int, vector<int>> p; // 有哪些需要前置条件

//         for (int i = 0; i < row; i ++) {
//             co[pre[i][0]] = 0; // 更新需要前置条件的 课程状态
//             p[pre[i][0]].push_back(pre[i][1]);

//             if (pre[i][1] == pre[i][0]) return false;
//         }

//         if (accumulate(co.begin(), co.end(), 0) <= 0) return false; // 没有前置课程可以学

//         // 递归
//         function<bool (int)> dfs = [&](int i) -> bool { // 第 i 门课
//             if (co[i] == 1) return 1; // 如果这门课已经学过了 直接返回结果
            
//             auto f = p[i]; // 前置课程;

//             bool idx = 1;

//             for (int k = 0; k < f.size(); k ++) {
//                 if (co[f[k]] == 0) {
//                     co[f[k]] = dfs(f[k]);
//                 }

//                 cout << f[k] << " " << co[f[k]] << endl;
//                 idx = (idx && co[f[k]]);
//             }

//             return (co[i] || idx);
//         };


//         for (int i = 0; i < numCourses; i ++) {
//             if (co[i] == 0) co[i] = dfs(i);
//         }
 
//         return (accumulate(co.begin(), co.end(), 0) >= numCourses);
//     }
// };
// @lc code=end

