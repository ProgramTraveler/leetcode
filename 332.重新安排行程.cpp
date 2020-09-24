/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    // 这里用map，内部自动按照string升序排列了，所以先找到的一定是自然排序最小的路径
    typedef unordered_map<string, map<string, int>> adjacent;// 记录从from到to的机票数
    vector<string> min_path;
    bool dfs(adjacent &adj, string airport){
        // 无脑dfs遍历邻居，同时遍历过的边标记已遍历
        for(auto &[next, number] : adj[airport]){
            // 若从airport到next的机票没有了，则遍历下一个
            if(0 >= number)
                continue;
            --number;// 从airport到next的机票数减一
            dfs(adj, next);
        }
        // 终点是没有相邻边的点
        // 当删除终点后，终点前的点也没有相邻边了，变成新的终点
        // 运行到这里，当前airport一定没有可遍历的相邻边了，则它是此时的终点
        min_path.push_back(airport);
        return true;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 初始化邻接表，因为存在多张相同机票的情况，所以邻接表中还记录了从from到to的机票数
        adjacent adj;
        for(auto & t : tickets){
            adj[t[0]][t[1]]++;
        }
        // Hierholzer算法，dfs无脑遍历
        dfs(adj, "JFK");

        // Hierholzer算法得到结果为终点到起点的路径，需要反转才是题目所要求的结果
        std::reverse(min_path.begin(), min_path.end());
        return min_path;
    }
};
// @lc code=end

