/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lc code=start
class Solution {
public:
    int func(string s) {
        int res = 1;

        sort(s.begin(), s.end());

        for (int i = 1; i < s.size(); i ++) {
            if (s[i] != s[i - 1]) break;

            res ++;
        }
        
        return res;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // 计算每个 string 中最小字母出现的频次
        vector<int> cnt_q, cnt_w;

        for (string s : queries) cnt_q.emplace_back(func(s));
        
        for (string s : words) cnt_w.emplace_back(func(s));

        vector<int> res(cnt_q.size(), 0);
        
        sort(cnt_w.begin(), cnt_w.end());
        // sort(cnt_q.begin(), cnt_q.end());

        // 递进搜索

        int idx = 0;

        for (int i = 0; i < cnt_q.size(); i ++) {
            int tem = 0;

            /*while (idx < cnt_w.size()) {
                if (cnt_w[idx] <= cnt_q[i]) idx ++;

                else {
                    tem = cnt_w.size() - idx;

                    break;
                }
            }*/

            for (int j = 0; j < cnt_w.size(); j ++) {
                if (cnt_w[j] > cnt_q[i]) {
                    tem = cnt_w.size() - j;

                    break;
                }
            }

            res[i] = tem;
        }

        return res;
    }
};
// @lc code=end

