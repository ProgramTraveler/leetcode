/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 *
 * [2288] 价格减免
 */

// @lc code=start
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double d = 1 - discount / 100.0;
        stringstream ss(sentence);
        string ans, w;
        while (ss >> w) { // 
            if (!ans.empty()) {
                ans += ' ';
            }
            if (w.length() > 1 && w[0] == '$' && 
            all_of(w.begin() + 1, w.end(), ::isdigit)) {
                stringstream s;
                s << fixed << setprecision(2) << '$' << stoll(w.substr(1)) * d;
                ans += s.str();
            } else {
                ans += w;
            }
        }

        return ans;
    }
};
// @lc code=end

