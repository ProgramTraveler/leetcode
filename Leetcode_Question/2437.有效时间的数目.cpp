class Solution {
public:
    int countTime(string time) {
        // 其实就排列组合的问题
        // h1 h2 : m1 m2
        /* 
        h1 为 0 h2 可以选 0-9
        h1 为 1 h2 可以选 0-9
        h1 为 2 h2 可以选 0-3

        m1 和 m2 无论前面是什么 m1 可以是 0-5 m2 可以是 0-9 
        */

        int cnt1 = 1, cnt2 = 1;
        int cnt3 = (time[3] == '?' ? 6 : 1), cnt4 = (time[4] == '?' ? 10 : 1);

        if (time[1] == '?') {
            if (time[0] == '?') cnt1 = 1, cnt2 = 24;
            
            else if (time[0] - '0' < 2) cnt1 = 1, cnt2 = 10;

            else cnt1 = 1, cnt2 = 4;
        }

        if (time[0] == '?' && isdigit(time[1])) {
            if (time[1] - '0' < 4) cnt1 = 3, cnt2 = 1;

            if (time[1] - '0' >= 4) cnt1 = 2, cnt2 = 1;
        }

        return cnt1 * cnt2 * cnt3 * cnt4;
    }
};