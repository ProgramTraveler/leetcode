/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;

        unordered_set<char> specials = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpacial = false;

        for (int i = 0; i < password.size(); i ++) {
            if (i != password.size() - 1 && password[i] == password[i + 1]) return false;

            if (islower(password[i])) hasLower = true;

            if (isupper(password[i])) hasUpper = true;

            if (isdigit(password[i])) hasDigit = true;

            if (specials.count(password[i])) hasSpacial = true;
        }

        return hasLower && hasUpper && hasDigit && hasSpacial;
    }
};
// @lc code=end

