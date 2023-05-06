/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 预处理每个字母在 "croak" 中的上一个字母
        char PREVIOUS['s']; // 's' 保证 "croak" 中的任意字符都不会越界
        const string croak = "croakc";
        for (int i = 1; i < croak.length(); i++)
            PREVIOUS[croak[i]] = croak[i - 1];

        int cnt['s']{};
        for (char ch: croakOfFrogs) {
            char pre = PREVIOUS[ch]; // pre 为 ch 在 "croak" 中的上一个字母
            if (cnt[pre]) // 如果有青蛙发出了 pre 的声音
                cnt[pre]--; // 复用一只
            else if (ch != 'c') // 否则青蛙必须从 'c' 开始蛙鸣
                return -1; // 不符合要求
            cnt[ch]++; // 发出了 ch 的声音
        }
        if (cnt['c'] || cnt['r'] || cnt['o'] || cnt['a'])
            return -1; // 有发出其它声音的青蛙，不符合要求
        return cnt['k']; // 最后青蛙们都发出了 'k' 的声音
    }
};

// class Solution {
// public:
//     int minNumberOfFrogs(string croakOfFrogs) {
//         int res = 0;

//         unordered_map<char, vector<int>> al;

//         int n = croakOfFrogs.size();

//         for (int i = 0; i < n; i ++) al[croakOfFrogs[i]].push_back(i);
        
//         // 如果每个字母的个数都不相等 其实可以直接返回 -1
//         if ((al['c'].size() != al['r'].size()) || (al['c'].size() != al['o'].size()) || (al['c'].size() != al['a'].size()) || (al['c'].size() != al['k'].size())) return -1;

//         int idx = 0, cnt = 0;

//         while (idx < al['c'].size()) {
//             auto idx_c = al['c'][idx];
//             auto idx_r = al['r'][idx];
//             auto idx_o = al['o'][idx];
//             auto idx_a = al['a'][idx];
//             auto idx_k = al['k'][idx];

//             if ((idx_c + 1 == idx_r) && (idx_r + 1 == idx_o) && (idx_o + 1 ==  idx_a) && (idx_a + 1 ==  idx_k)) cnt ++;

//             idx ++;
//         }

//         idx = 0;

//         while (idx < al['c'].size()) {
//             auto idx_c = al['c'][idx];
//             auto idx_r = al['r'][idx];
//             auto idx_o = al['o'][idx];
//             auto idx_a = al['a'][idx];
//             auto idx_k = al['k'][idx];

//             if ((idx_c < idx_r) && (idx_r < idx_o) && (idx_o < idx_a) && (idx_a < idx_k)) res ++;

//             idx ++;
//         }

//         cnt == 0 ? cnt = res : cnt = res - cnt + 1;

//         return res * 5 == n ? cnt : -1;
//     }
// };
// @lc code=end

