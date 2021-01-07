/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        for(int j = 0; j < isConnected.size(); j ++){
            // 如果相连且未访问
            if(isConnected[i][j] == 1 && !visited[j]){
                // 标记为访问过
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // bool型判断矩阵，判断是否访问过
        vector<bool> visited(isConnected.size(), false);
        int res = 0;
        for(int i = 0; i < isConnected.size(); i ++){
            // 如果未访问
            if(!visited[i]){
                dfs(isConnected, visited, i);
                res ++;
            }
        }
        return res;
    }

};

// @lc code=end

