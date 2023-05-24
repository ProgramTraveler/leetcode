/*
 * @lc app=leetcode.cn id=1090 lang=cpp
 *
 * [1090] 受标签影响的最大值
 */

// @lc code=start
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();

        vector<int> id(n);
        
        // 对下标进行排序
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return values[i] > values[j];
        });

        int res = 0, choose = 0;
        unordered_map<int, int> cnt;

        for (int i = 0; i < n && choose < numWanted; i ++) {
            int label = labels[id[i]];

            if (cnt[label] == useLimit) continue; // 跳过循环中余下的语句

            choose ++;
            res += values[id[i]];
            cnt[label] ++;
        }

        return res;

        /*int res = 0;

        unordered_map<int, vector<int>> al; // values 对应的 labels
        unordered_map<int, int> cnt; // labels 对应的个数

        for (int i = 0; i < values.size(); i ++) al[values[i]].emplace.back(labels[i]);
        
        sort(values.begin(), values.end(), greater<int>());

        int idx = 0;

        while (numWanted > 0) {


        }

        return res;*/
    }
};
// @lc code=end

