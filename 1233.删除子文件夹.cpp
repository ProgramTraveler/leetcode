/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // 做一个简单的检测

        sort(folder.begin(), folder.end()); // 按字典进行排序

        vector<string> res;

        res.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i ++) {
            string s1 = res[res.size() - 1], s2 = folder[i];

            int idx = 0;

            for (idx = 0; idx < s1.size() && idx < s2.size(); idx ++) if (s1[idx] != s2[idx]) break;
            
            if (s2[idx] != '/') res.push_back(folder[i]); // 如果不是子文件
            
        }

        return res;
    }
};
// @lc code=end

