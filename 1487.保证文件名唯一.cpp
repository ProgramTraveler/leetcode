/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution {
public:
    string addFun(string s, int k) {
        return s + "(" + to_string(k) + ")";
    }
    vector<string> getFolderNames(vector<string>& names) {
        /*unordered_map<string, int> al;
        vector<string> res;

        //for (auto st : names) al[st] = 0;

        for (auto st : names) {
            if (al[st] > 0) { // 说明已经存在了
                string tem = st;
                int idx = 1;

                tem.push_back('(');
                tem.push_back(idx + '0');
                tem.push_back(')');

                while (al[tem] != 0) {
                    tem[tem.size() - 2] = (idx + '0');
                    idx ++;
                }

                res.push_back(tem);
                al[tem] ++;

            } else {
                al[st] ++;
                res.push_back(st);
            }
        }

        return res;*/
        unordered_map<string, int> idx;
        vector<string> res;

        for (auto st : names) {
            if (!idx.count(st)) {
                res.push_back(st);
                idx[st] = 1;
            } else {
                int k = idx[st];
                while (idx.count(addFun(st, k))) {
                    k ++;
                }

                res.push_back(addFun(st, k));
                idx[st] = k + 1;
                idx[addFun(st, k)] = 1;
            }
        }

        return res;
    }
};
// @lc code=end

