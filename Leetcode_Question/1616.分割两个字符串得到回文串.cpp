/*
 * @lc app=leetcode.cn id=1616 lang=cpp
 *
 * [1616] 分割两个字符串得到回文串
 */

// @lc code=start
class Solution {
public:
    /*bool fun (queue<char> q1, queue<char> q2) {
        string s1, s2;

        while (!q1.empty()) s1 += q1.front(), q1.pop();
        while (!q2.empty()) s2 += q2.front(), q2.pop();

        string s = s1 + s2;

        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) return false;

            l ++, r --;
        }

        return true;
    }*/

    /*bool fun(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (s[l] != s[r]) return false;

            l ++, r --;
        }

        return true;
    }*/

    bool isFun(string &s, int i, int j) {
        while (i < j && (s[i] == s[j])) i ++, j --;

        return i >= j;
    }

    bool cheak(string &a, string &b) {
        int i = 0, j = a.size() - 1;

        while (i < j && (a[i] == b[j])) i ++, j --;

        return isFun(a, i, j) || isFun(b ,i ,j);
    }

    bool checkPalindromeFormation(string a, string b) {
        // a b 长度相同
        // 分割的下标位置相同
        // 分割的字符串可以为空

        /*bool res_a = true, res_b = true, res_ab = true;

        // 先判断 a b 是不是回文字符串
        int l = 0, r = a.size() - 1;

        while (l <= r) {
            if (a[l] != a[r]) res_a = false; // a 不是回文

            if (b[l] != b[r]) res_b = false; // b 不是回文

            l ++, r --;
        }

        if (res_a || res_b) return true;*/

        // reverse(a.begin(), a.end());

        // int idx = 0;


        // 这么做超时了
        /*queue<char> ap, as, bp, bs;

        for (int i = 0; i < a.size(); i ++) as.push(a[i]), bs.push(b[i]);
        

        for (int i = 0; i < a.size(); i ++) {
            ap.push(a[i]), as.pop();

            bp.push(b[i]), bs.pop();

            res_ab = (fun(ap, bs) || fun(bp, as));

            if (res_ab) return true;
        } */
        
        // 优化了一下还是超时了
        /*string ap, bp;
        string as = a, bs = b;

        for (int i = 0; i < a.size(); i ++) {
            ap += a[i], bp += b[i];

            // 超时的问题应该还是对字符串处理的这部分
            bs.replace(0, ap.size(), ap);

            as.replace(0, bp.size(), bp);

            res_ab = (fun(bs) || fun(as));

            if (res_ab) return true;
        }*/


        return cheak(a, b) || cheak(b, a);
    }
};
// @lc code=end

