/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        // source[i] 表示第 i 行代码
        // 检查字符串的开始字符和结束字符
        vector<string> ans;

        int state = 0;
        string curr;
        
        for (string &line : source) {
            int start = 0;
            while (true) {
                if (state == 0) {
                    size_t p1 = line.find("//", start);
                    size_t p2 = line.find("/*", start);
                    if (p2 < p1) {
                        curr += line.substr(start, p2 - start);
                        state = 1;
                        start = p2 + 2;
                        continue;
                    } else {
                        curr += line.substr(start, p1 - start);
                        if (!curr.empty()) ans.push_back(curr);
                        curr = "";
                        break;
                    }
                } else {
                    size_t p = line.find("*/", start);
                    if (p == string::npos) {
                        break;
                    } else {
                        state = 0;
                        start = p + 2;
                    }
                }
            }
        }
        return ans;



        /*int idx = 0;
        int n = source.size();

        vector<string> res;

        while (idx < n) {
            string sour = source[idx];

            // 查找 / 第一次在 sour 中出现的位置

            int fl = sour.find('/'); // '/' 最先出现的位置
            int st = sour.find('*'); // '*' 最先出现的位置

            // 判断是哪种注释
            if (fl >= 0 && sour[fl + 1] == '/') sour = sour.substr(0, fl);

            else if (st > 0 && sour[st - 1] == '/') {

                sour = sour.substr(0, st - 1);

                int idx_tem = idx;
                while (idx_tem < n) {
                    string sour_tem = source[idx_tem];
                    int f1 = 0;
                    if (idx_tem == idx) f1 = sour_tem.rfind('*'); // '*' 最后出现的位置
                    else f1 = sour_tem.find('*');
                
                    if (f1 > 0 && sour_tem[f1 + 1] == '/') {
                        sour_tem = sour_tem.substr(f1 + 2);

                        sour += sour_tem;

                        idx = idx_tem;

                        break;
                    }

                    idx_tem ++;
                }
            }

            if (sour.size() != 0) res.emplace_back(sour);

            idx ++;
        }

        return res;*/
    }
};
// @lc code=end

