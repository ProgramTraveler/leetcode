/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res (score.size(), "a"); //记录最终的结果 

        unordered_map <int, int> M; //保存原始数组的相对位置

        for (int i = 0; i < score.size(); i ++)
            M[score[i]]  = i;
        
        sort(score.begin(), score.end(), greater<int>()); //对原数组进行排序，注意按照从大到小进行排序
        
        //遍历处理后数组，进行不同情况的赋值
        for (int i = 0; i < score.size(); i ++) {
            if (i == 0)
                res[M[score[i]]] = "Gold Medal";
            else if (i == 1)
                res[M[score[i]]] = "Silver Medal";
            else if (i == 2)
                res[M[score[i]]] = "Bronze Medal";
            else
                res[M[score[i]]] = to_string(i + 1);
        }

        //reverse(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

