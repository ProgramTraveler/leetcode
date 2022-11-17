/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    /*int cheak (string s, unordered_map<int, queue<int>> stl, int al[26]) {
        if (s.size() == 1 && stl[s[0] - 'a'].front() > 0) return 1;

        int idx = stl[s[0] - 'a'].front(), idx_fro = stl[s[1] - 'a'].front(); // 更新第一个和第二个字母的最初位置
        stl[s[0] - 'a'].pop(), stl[s[1] - 'a'].pop(); // 将已经赋值的下标弹出

        int i = 1;
        
        while (i < s.size()) {
            if (al[s[i] - 'a'] == 0) return 0;

            if (idx_fro > idx) { // 如果当前的字母下标比上一个字母的下标大 满足条件

                idx = stl[s[i] - 'a'].front(); // 将当前字母的下标作为下一个参考的依据

                stl[s[i] - 'a'].pop(); // 弹出
                
                i ++; // 移动至下一个字母
                
                idx_fro = stl[s[i] - 'a'].front(); // 赋值当前下标

                stl[s[i] - 'a'].pop(); // 弹出

            } else { // 如果当前下标比之前小

                stl[s[i] - 'a'].pop(); // 弹出前一个下标

                if (stl[s[i] - 'a'].empty()) return 0; // 如果已经弹空队列 但是没有超过之前字母下标的值 说明没有
                else idx_fro = stl[s[i] - 'a'].front();
            }
         }

        return 1;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0, al[26] = {0};

        unordered_map<int, queue<int>> stl; // 记录每个字母出现的所有下标

        for (int i = 0; i < s.size(); i ++) stl[s[i] - 'a'].push(i + 1), al[s[i] - 'a'] ++; // 更新每个字母最早出现的下标位置

        //cout << stl['b' - 'a'].front() << "-" << stl['b' - 'a'].empty() << endl;

        for (int i = 0; i < words.size(); i ++) {
            res += cheak(words[i], stl, al); 

            cout << cheak(words[i], stl, al) << " " << words[i] << endl;
        }
    
        return res;

    }*/
    
    int numMatchingSubseq(string s, vector<string> &words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto &w : words) {
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w) {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};

// @lc code=end

