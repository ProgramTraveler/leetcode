class Solution {
public:
    int countDigits(int num) {
        int res = 0;

        vector<int> cnt;

        int n = num;

        while (n) {
           res += (num % (n % 10)) == 0 ? 1 : 0;

            n /= 10;
        }

        return res;
    }
};