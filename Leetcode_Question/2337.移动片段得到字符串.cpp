/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

// @lc code=start
class Solution {
public:
    bool canChange(string start, string target) {
        /*
        // 双指针
        int n = start.size();

        // 记录 start 中的 l 和 r 的下标位置
        unordered_map<char, vector<int>> cor_s;

        // 记录 target 中的 l 和 r 的下标位置
        unordered_map<char, vector<int>> cor_t;


        for (int i = 0; i < n; i ++) cor_s[start[i]].emplace_back(i), cor_t[target[i]].emplace_back(i);


        int l_ = 0, r_ = 0;
        for (int i = 0; i < n; i ++) if (start[i] == '_') l_ = min(l_, i), r_ = max(r_, i);
        
        auto vl = cor_s['L'];
        reverse(vl.begin(), vl.end());
        auto vr = cor_s['R'];
        // reverse(vr.begin(), vr.end());

        auto tl = cor_t['L'];
        reverse(tl.begin(), tl.end());
        auto tr = cor_t['R'];
        // reverse(tr.begin(), tr.end());

        // cout << vl.size() << '-' << vr.size() << endl;

        while (vl.size() > 0 && tl.size() > 0) {
            int nl = vl.size() - 1;
            int ntl = tl.size() - 1;

            if (vl[nl] - tl[ntl] <= vl[nl] - l_ && (vl[nl] - l_) > 0 && (vl[nl] - tl[ntl]) > 0) {
                l_ = tl[ntl] + 1; // 更新坐标存在 '_' 的最小下标
                
                start[tl[ntl]] = 'L'; // 更新 start 中的 l
                start[vl[nl]] = '_'; // 更新原 l

            } else return false;

            vl.pop_back();
            tl.pop_back(); 
        }

        while (vr.size() > 0 && tr.size() > 0) {
            int nr = vr.size() - 1;
            int ntr = tr.size() - 1;

            // cout << nr << " " << ntr << endl;

            if (tr[ntr] - vr[nr] <= r_ - vr[nr] && (r_ - vr[nr]) > 0 && (tr[ntr] - vr[nr]) > 0) {
                r_ = tr[ntr] - 1;

                start[tr[ntr]] = 'R';
                start[vr[nr]] = '_';
                
            } else return false;

            vr.pop_back();
            tr.pop_back();            
        }

        cout << start << " === " << target << endl;

        return !start.compare(target);
        */


        auto s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if (s != t) return false;
        for (int i = 0, j = 0; i < start.length(); i++) {
            if (start[i] == '_') continue;
            while (target[j] == '_')
                j++;
            if (i != j && (start[i] == 'L') == (i < j))
                return false;
            ++j;
        }
        return true;
    }
};
// @lc code=end

