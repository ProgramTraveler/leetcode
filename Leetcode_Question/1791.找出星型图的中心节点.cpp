/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

// @lc code=start
class Solution {
    public int findCenter(int[][] edges) { //其实就是中心数字出现的次数和总次数是一样的
        int ans = 0;
        Map<Integer, Integer> m = new HashMap<>();
        for (int[] edge : edges) {
            m.put(edge[0], m.getOrDefault(edge[0], 0) + 1);
            m.put(edge[1], m.getOrDefault(edge[1], 0) + 1);
        }
        int N = m.size();
        for (int key : m.keySet()) {
            if (m.get(key) == N -1) return key;
        }
        return -1;
    }
}
// @lc code=end

