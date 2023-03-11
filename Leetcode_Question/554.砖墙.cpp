/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> map;
        int n = wall.size();
        //这个for循环写的还是比较有意思
        for (int i = 0, sum = 0; i < n; i ++, sum = 0) {
            //for循环的这种写法也多用用
            for (int cur : wall[i]) {
                sum += cur;
                map[sum] ++;
            }
            map.erase(sum);
        }
        int res = n;
        //对map进行遍历操作，这个掌握一下，有的时候向写但写不出来
        for (auto &[u, cur] : map) {
            res = min(res, n - cur);
        }
        return res; 
    }
};
// @lc code=end

