/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        map<int, int> m;

        int res = 0;

        for (int i = 0; i < 10; i ++) {
            switch(i) {
                case 0 : 
                    m[i] = 0;
                    break;
                case 1 : 
                    m[i] = 1;
                    break;
                case 2 :
                    m[i] = 5;
                    break;
                case 5 :
                    m[i] = 2;
                    break;
                case 6 :
                    m[i] = 9;
                    break;
                case 8 :
                    m[i] = 8;
                    break;
                case 9 :
                    m[i] = 6;
                    break;
                default : m[i] = -1; 
            }
        }
        for (int i = 0; i <= n; i ++) {

            int count = 0, temp = i;

            stack<int> s;

            bool f = true;

            while (temp != 0) {
                s.push(temp % 10);
                temp = temp / 10;
            }

            while (!s.empty()) {
                if (m[s.top()] != -1) {
                    count = count * 10 + m[s.top()];
                    s.pop();
                } else {
                    f = false;
                    break;
                }
            }

            if (f && count != i) res ++;
        }

        return res;    

    }
};
// @lc code=end

