class Solution {
public:
    string printBin(double num) { // 小数变二进制数
        string res = "0.";

        while (res.size() <= 32 && num != 0) { // 题目要求 二进制不超过 32 位
            num *= 2;

            int digit = num;

            res.push_back(digit + '0');

            num -= digit;
        }

        return res.size() > 32 ? "ERROR" : res;
    }
};